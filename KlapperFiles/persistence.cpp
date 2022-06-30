#include "persistence.h"
#include <stdio.h>
#include <iostream>
Persistence::Persistence(std::vector<std::vector<Node>> nodes)
{
this->nodes = nodes;
}

pqxx::connection Persistence::getConnection()
{
    pqxx::connection conn{"postgres://ymcbvebm:naW5cZI-1o7azsZk1QfAB3CrnMTni0We@abul.db.elephantsql.com/ymcbvebm"};
   return conn;
}

std::string Persistence::getConnectionString()
{
    return connectionString;
}


void Persistence::loadNode(std::string nodeId)
{
    pqxx::connection conn = this->getConnection();
    pqxx::work tah{conn};


}

void Persistence::saveNodes()
{
    pqxx::connection conn = this->getConnection();
    pqxx::work tah{conn};
    
    //prepared statement that can be used multiple times and is not easily sqlinjected
     conn.prepare("UpdateWeight","Update nodes Set weights = $1 WHERE id = $2");
    for(int i = 0; i<nodes.size();i++){

    for(int j =0; j< nodes.at(i).size();j++){
        std::string id = nodes.at(i).at(j).getId();
        std::string weightString = generateWeightQueryString(i,j);



        try{
        // Execute the prepared statement and save it as a result
        pqxx::result r = tah.exec_prepared("UpdateWeight",weightString,id);


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
      std::cout << "Succesfully saved node weights" << std::endl;
    }
    catch(std::exception e){
        std::cout << e.what() << std::endl;
        std::cout << " saveNodes() Failed to commit" << std:: endl;}

}

void Persistence::generateFreshNodes(){
    pqxx::connection conn = this->getConnection();
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

std::string Persistence::generateWeightQueryString(int nodeX, int nodeY){

    std::string weightString = "{";
    for(int n = 0; n<10;n++){
        float weight = nodes.at(nodeX).at(nodeY).getWeight(n);
        std::string weightValString = std::to_string(weight);
        weightString.append("\"");
        weightString.append(weightValString);
        weightString.append("\"");
        if(n!=9){
            weightString.append(",");
        }
    }
    weightString.append("}");
    std::cout << weightString << std::endl;
    return weightString;
}

void Persistence::moveTrainedData(int id)
{

}

