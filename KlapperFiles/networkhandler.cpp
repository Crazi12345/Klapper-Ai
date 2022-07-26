#include "networkhandler.h"

#include <math.h>

NetworkHandler::NetworkHandler()
{

}
NetworkHandler::NetworkHandler(int inputNodeCount,int numberOfLayers,int numberOfNodes){

    this->inputNodeCount = inputNodeCount;
    this->numberOfLayers = numberOfLayers;
    this->numberOfNodes = numberOfNodes;
    bias_weight_change_Clear();

}



void NetworkHandler::generateNodes(){

    std::vector<Node> temp;
    Persistence p;
     // Loop to generate the inputLayer

        std::cout << "Generating Input Layer" << std::endl;
    for(int i = 0; i<inputNodeCount;i++){
    Node* n = new Node(0,i);
    std::vector<long> w = p.loadNode(n->getId());

    n->loadWeight(w);
    temp.push_back(*n);

    }
   nodes.push_back(temp);

      //Generate input bias node
   for(int i = 0; i < 10; i++){
       float random_weight = (rand()%100 - 50);
       bias_weight[0][i] = random_weight;
   }

   // Loop to generate the Hidden Layers
    std::cout << "Generating Hidden Layer" << std::endl;
   int tempNumOfNodes = numberOfNodes;
   for(int i = 1; i<numberOfLayers;i++){
       temp.clear();
       for(int j = 0; j<tempNumOfNodes;j++){
           Node* n = new Node(i,j);
           std::vector<long> w = p.loadNode(n->getId());
            n->loadWeight(w);
            temp.push_back(*n);
}
            nodes.push_back(temp);

   }
    // making the last output Node
   Node* n = new Node(nodes.size(),0);
   temp.clear();
   temp.push_back(*n);
   nodes.push_back(temp);

}
void NetworkHandler::generateRandomWeightNodes(){
    nodes.clear();
    bias_weight_change_Clear();

    std::vector<Node> temp;
    for(int i = 0; i<inputNodeCount;i++){ 

        Node* n = new Node(0,i);
        for(int weight_index = 0; weight_index < 10; weight_index++){

            n->setRandomWeight(20, weight_index);

        }
        temp.push_back(*n);

    }

    nodes.push_back(temp);

    for(int i = 0; i < 10; i++){
        //Generate input bias node
        float random_weight = (rand()%100 - 50);
        bias_weight[0][i] = random_weight;
    }


    // Loop to generate the Hidden Layers
    int tempNumOfNodes = numberOfNodes;
    for(int i = 1; i<numberOfLayers;i++){
        temp.clear();
        for(int j = 0; j<tempNumOfNodes;j++){
            Node* n = new Node(i,j);
            for(int weight_index = 0; weight_index < 10; weight_index++){
                n->setRandomWeight(100, weight_index);
            }

            //Generate bias hidden nodes
            float random_weight = (rand()%50 - 25);
            bias_weight[i][j] = random_weight;


            temp.push_back(*n);
        }
        nodes.push_back(temp);
        //tempNumOfNodes += 2;

    }


    // making the last output Node
    Node* n = new Node(nodes.size(),0);
    temp.clear();
    temp.push_back(*n);
    nodes.push_back(temp);


}

void NetworkHandler::bias_weight_change_Clear(){

    int array_size        = sizeof(bias_weight_change)/sizeof(bias_weight_change[0]);
    Persistence persistence;
    int double_array_size = sizeof(bias_weight_change[0])/sizeof(bias_weight_change[0][0]);

    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < double_array_size; j++){
            bias_weight_change[i][j] = 0;
        }
    }
}

std::vector<std::vector<Node>> NetworkHandler::getNodes(){
    return nodes;
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

                std::cout << nodes.at(j).at(i).getId() << "     ";
            }
            else{
                std::cout << "     ";
            }
        }
        std::cout << std::endl;
    }
}

void NetworkHandler::BackProp(float nn_output, float clapSound)
{
    batchAmount++;
    backpropagation bp(&nodes, startlayer_outputs, &(hiddenlayer_outputs[0][0]), &nn_output, &(bias_weight_change[0][0]));
    bp.backpropagate(clapSound);

}

void NetworkHandler::UpdateNeuralNetwork()
{


for(int i = 0; i < nodes.size(); i++){

    for(int j = 0; j < nodes.at(i).size(); j++){
        nodes.at(i).at(j).CommitAVGWeightChange(batchAmount);
    }

}



int array_size        = sizeof(bias_weight_change)/sizeof(bias_weight_change[0]);
int double_array_size = sizeof(bias_weight_change[0])/sizeof(bias_weight_change[0][0]);

for(int i = 0; i < array_size; i++){
    for(int j = 0; j < double_array_size; j++){
        bias_weight_change[i][j] /= batchAmount;
        bias_weight[i][j] += bias_weight_change[i][j];

        bias_weight_change[i][j] = 0;
    }
}

batchAmount = 0;

}


float NetworkHandler::CalculateOutput(std::vector<int> &inputs)
{

    if ((int)inputs.size() != inputNodeCount){
        std::cout << "input amount does not match network input nodes amount" << std::endl;
        return 0;
    }
    //input node count amount of nodes, that each has 10 values stemming from 10 different weights
    float Output_inputLayer[inputNodeCount];

    float Output_hiddenLayers[numberOfLayers-1][numberOfNodes];

    //10 nodes who each has 10 different values stemming from 10 different weights.
    float layervalues[numberOfNodes];

    //Start with the second first layer, and sum all the values from the previous layer
    //get all layers -> 1 : 4
    for(int i = 1; i < (int)nodes.size(); i++){

        //Collect output data from all nodes.
        for(int j = 0; j < (int)nodes.at(i-1).size(); j++){
            if(i == 1){
                float node_value = inputs.at(j);
                Output_inputLayer[j] = node_value;
            }else{
                float node_value = sigmoid(layervalues[j]);
                Output_hiddenLayers[i-2][j] = node_value;
            }
        }


        //All nodes in the layer -> 0 : 9 OR 0 if output layer, i == 4
        for(int j = 0; j < (int)nodes.at(i).size(); j++){
            float addition_counter = 0;
            float value = 0;

            for(int p = 0; p < (int)nodes.at(i-1).size(); p++){
                float node_weight = nodes.at(i-1).at(p).getWeight(j);

                if(i == 1){
                    value += Output_inputLayer[p]*node_weight;

                }else{
                    value += Output_hiddenLayers[i-2][p]*node_weight;

                }

                addition_counter++;

            }

            value += bias_weight[i-1][j];
            addition_counter++;

            layervalues[j] = value/addition_counter;

        }
    }

    float output = layervalues[0];

    for(int i = 0; i < inputNodeCount; i++){
        startlayer_outputs[i] = Output_inputLayer[i];
    }


    for(int i = 0; i < numberOfLayers-1; i++){
        for(int j = 0; j < numberOfNodes; j++){
            hiddenlayer_outputs[i][j] = Output_hiddenLayers[i][j];
        }
    }


    //Return sigmoid of the last node.
    return sigmoid(output);

}


double NetworkHandler::sigmoid(double x){

    return(1/(1+pow(2.71828,-1*x)));
}











