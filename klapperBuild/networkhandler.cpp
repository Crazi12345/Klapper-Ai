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
    { Node* n = new Node(0,i);
        for(int weight_index = 0; weight_index < 10; weight_index++){
            n->setweight(1, weight_index);
        }
     temp.push_back(*n);
    }
    nodes.push_back(temp);


    // Loop to generate the Hidden Layers
    int tempNumOfNodes = numberOfNodes;
    for(int i = 1; i<numberOfLayers;i++){
        temp.clear();
        for(int j = 0; j<tempNumOfNodes;j++){
            Node* n = new Node(i,j);
            for(int weight_index = 0; weight_index < 10; weight_index++){
                n->setweight(1, weight_index);
            }
            temp.push_back(*n);
        }
        nodes.push_back(temp);
        //tempNumOfNodes += 2;
    }

    // making the last output Node
    Node* n = new Node(nodes.size()-1,0);
    temp.clear();
    temp.push_back(*n);
    nodes.push_back(temp);


}

void NetworkHandler::PrettyPrint(){


    bool rows[nodes.size()];
    for(int b = 0; b<(int)nodes.size();b++){rows[b]=true;}

    for(int i =0; i<inputNodeCount;i++){
        for(int j =0; j<(int)nodes.size();j++){
            if((int)nodes.at(j).size()<=i){
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

void NetworkHandler::BackProp(){

    backpropagation bp(&nodes);


}

float NetworkHandler::CalculateOutput(std::vector<int> inputs)
{
    if ((int)inputs.size() != inputNodeCount){
        std::cout << "input amount does not match network input nodes amount" << std::endl;
        return 0;
    }
    //input node cound amount of nodes, that each has 10 values stemming from 10 different weights
    float startValues[inputNodeCount][numberOfNodes];

    //10 nodes who each has 10 different values stemming from 10 different weights.
    float layervalues[numberOfNodes];
    for(int i = 0; i < numberOfNodes; i++){
        layervalues[i] = 0;
    }

    //Assign start values to the weights of the first 500 nodes multiplied by their numbers.
    for(int i = 0; i < inputNodeCount; i++){
        for(int j = 0; j < numberOfNodes; j++){

            float node_value = nodes.at(0).at(i).sigmoid(inputs.at(i));
            float node_weight = nodes.at(0).at(i).getWeight(j);

            startValues[i][j] = node_weight*node_value;
        }
    }


    //Start with the second first layer, and sum all the values from the previous layer
    //get all layers -> 1 : 4
    for(int i = 1; i < (int)nodes.size(); i++){

        //All nodes in the layer -> 0 : 9 OR 0 if output layer, i == 4
        for(int j = 0; j < (int)nodes.at(i).size(); j++){
            int addition_amounts = 0;

            float value = 0;

            //All nodes in the previous layer -> 0 : 9 OR 0 : 499 if i == 1
            for(int p = 0; p < (int)nodes.at(i-1).size(); p++){
                if(i == 1){
                    value += startValues[p][j];
                }else{
                    float node_values = nodes.at(i-1).at(p).sigmoid(layervalues[j]);
                    float node_weight = nodes.at(i-1).at(p).getWeight(j);
                    value += node_values*node_weight;
                }
                addition_amounts++;
            }
            layervalues[j] = value/addition_amounts;
        }
    }

    float output = layervalues[0];

    //Return sigmoid of the last node.
    return nodes.at(nodes.size()-1).at(0).sigmoid(output);

}











