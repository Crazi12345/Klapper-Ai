#include "networkhandler.h"

NetworkHandler::NetworkHandler()
{

}
NetworkHandler::NetworkHandler(int inputNodeCount,int numberOfLayers,int numberOfNodes){

    this->inputNodeCount = inputNodeCount;
    this->numberOfLayers = numberOfLayers;
    this->numberOfNodes = numberOfNodes;

}

void NetworkHandler::generateNodes(){

    // Loop to generate the inputLayer
    std::vector<Node> temp;
    for(int i = 0; i<inputNodeCount;i++)
    { Node* n = new Node;
     temp.push_back(*n);
    }
    nodes.push_back(temp);


    // Loop to generate the Hidden Layers
    int tempNumOfNodes = numberOfNodes;
    for(int i = 1; i<numberOfLayers;i++){
        temp.clear();
        for(int j = 0; j<tempNumOfNodes;j++){
            Node* n = new Node;
            temp.push_back(*n);
        }
        nodes.push_back(temp);
        tempNumOfNodes += 2;
    }

    // making the last output Node
    Node* n = new Node;
    temp.clear();
    temp.push_back(*n);
    nodes.push_back(temp);


}

void NetworkHandler::PrettyPrint(){
    // Not working currently

    bool rows[nodes.size()];
    for(int b = 0; b<nodes.size();b++){rows[b]=true;}

    for(int i =0; i<inputNodeCount;i++){
        for(int j =0; j<nodes.size();j++){
            if(nodes.at(j).size()<=i){
                rows[j]=false;
            }
            if(rows[j]==true){
                std::cout << "*  ";
            }
            else{
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }
}













