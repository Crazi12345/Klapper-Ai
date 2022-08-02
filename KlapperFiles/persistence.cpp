#include "persistence.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
Persistence::Persistence()
{
this->loadNodeData();
this->loadTrainingData();
}




std::string Persistence::getConnectionString()
{
    return connectionString;
}


void Persistence::loadNodeData(){
    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};

    conn.prepare("FindWeight","select * from nodes");
    pqxx::result r = tah.exec_prepared("FindWeight");
    nodeData = r;
}

std::vector<long> Persistence::loadNode(std::string nodeId)
{
   // std::cout << "Finding weights for node: " << nodeId << std::endl;

    int row,col;
       iterationNum+=1;
    for(iterator=0;iterator<541;iterator++){
            std::string idString = pqxx::to_string(nodeData[iterator][0]);
             //   std::cout << idString << std::endl;
            if(idString == nodeId){
                row=iterator;
            //    std::cout << "Found" << "idString: "<< idString << " and NodeId: " << nodeId<< std::endl;
                break;
            }

}
  //  std::cout << iterationNum<< std::endl;



    std::vector<long> found_messages;
    auto arr = nodeData[row][1].as_array();
    std::pair<pqxx::array_parser::juncture, std::string> elem;
    do
    {
        elem = arr.get_next();
        if (elem.first == pqxx::array_parser::juncture::string_value)
            found_messages.push_back(stoul(elem.second));
    }
    while (elem.first != pqxx::array_parser::juncture::done);
    //std::cout << "Weights Found "<< std::endl;
    //std::cout << std::endl;

   return found_messages;
}

void Persistence::saveNodes(std::vector<std::vector<Node>> nodes)
{
    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};

    std::cout << "Trying to save Nodes Weights"<<std::endl;
    bool isWorking = true;


    //prepared statement that can be used multiple times and is not easily sqlinjected
     conn.prepare("UpdateWeight","Update nodes Set weights = $1 WHERE id = $2");

     for(int i = 0; i<nodes.size();i++){
      for(int j =0; j< nodes.at(i).size();j++){
        std::string id = nodes.at(i).at(j).getId();
        std::string weightString = generateWeightQueryString(i,j,nodes);

        try{
        // Execute the prepared statement and save it as a result
        pqxx::result r = tah.exec_prepared("UpdateWeight",weightString,id);
        }
        catch(pqxx::sql_error e){
             std::cout << e.what() << std::endl;
             isWorking = false;
        }
        catch(std::exception e){
            std::cout << e.what() << std::endl;
            isWorking = false;
        }
    }

  }
    if(isWorking){
    try{
     tah.commit();
      std::cout << "Succesfully saved node weights" << std::endl;
    }
    catch(std::exception e){
        std::cout << e.what() << std::endl;
        std::cout << " saveNodes() Failed to commit" << std:: endl;}
    }
    else{
        std::cout << "There were errors did not commit";
    }

}


void Persistence::generateFreshNodes(std::vector<std::vector<Node>> nodes){

    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};

    conn.prepare("deleteNodes","DROP table nodes");
     conn.prepare("genTable",
                  "Create table nodes("
                  "  id varchar(64),"
                " weights decimal[]"
              ");");
     tah.exec_prepared("deleteNodes");
     tah.exec_prepared("genTable");

    //prepared statement that can be used multiple times and is not easily sqlinjected
     conn.prepare("insertNode","INSERT INTO nodes(id)Values($1)");

   for(int i = 0; i<nodes.size();i++){
    for(int j =0; j< nodes.at(i).size();j++){
        std::string id = nodes.at(i).at(j).getId();

        float weights[10];
        try{
        // Execute the prepared statement and save it as a result
        pqxx::result r = tah.exec_prepared("insertNode",id);


        }
        catch(pqxx::sql_error e){
            std::cout << e.what() << std::endl;
        }

        catch(std::exception e){
            std::cout << e.what() << std::endl;
        }
}

    }
    try{
     tah.commit();
      std::cout << "Succesfully committed changes" << std::endl;
    }
    catch(std::exception e){
        std::cout << e.what() << std::endl;
        std::cout << "Failed to commit" << std:: endl;}




}

std::string Persistence::generateWeightQueryString(int nodeX, int nodeY,std::vector<std::vector<Node>> nodes){

    std::string weightString = "{";
    for(int n = 0; n<10;n++){
        float weight = nodes.at(nodeX).at(nodeY).getWeight(n);
        std::string weightValString = std::to_string(weight);
        weightString.append("\"");
        weightString.append(weightValString);
        weightString.append("\"");
        if(n!=9){
            weightString.append(",");}
    }
    weightString.append("}");

    return weightString;
}

void Persistence::loadTrainingData(){
    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};

    conn.prepare("FindTrainingData","select * from untrained_data");
    pqxx::result r = tah.exec_prepared("FindTrainingData");
    trainingData = r;
}
std::vector<int> Persistence::getDataRow(){


        std::vector<int> found_data;
        auto arr =  trainingData[0][1].as_array();
        std::pair<pqxx::array_parser::juncture, std::string> elem;
        do
        {
            elem = arr.get_next();
            if (elem.first == pqxx::array_parser::juncture::string_value)
                found_data.push_back(stoul(elem.second));
        }
        while (elem.first != pqxx::array_parser::juncture::done);

    if(found_data.size()<=0){
        std::cout << "No more data" << std::endl;

    }
    moveTrainedData();
    return found_data;


}

void Persistence::moveTrainedData()
{
    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};

    conn.prepare("ChangeDataLocation","insert into trained_data(id,data,label) "
                                      "select * from untrained_data fetch first 1 row only;");
    conn.prepare("DeleteDataFromLocation",
                 "DELETE from untrained_data where id in ( select id from trained_data fetch first 1 row only )");
     tah.exec_prepared("ChangeDataLocation");
     tah.exec_prepared("DeleteDataFromLocation");
     tah.commit();

    loadTrainingData();

}

void Persistence::moveTrainedDataBack()
{
    pqxx::connection conn{getConnectionString()};
    pqxx::work tah{conn};
    conn.prepare("MoveDataBack","insert into untrained_data(id,data,label) "
                                       "select id,data,label from trained_data");
    conn.prepare("DeleteDataLocation",
                 "DELETE from trained_data where id in ( select id from trained_data)");
    tah.exec_prepared("MoveDataBack");
    tah.exec_prepared("DeleteDataLocation");
    tah.commit();

}

