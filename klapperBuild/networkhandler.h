#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H
#include <iostream>
#include "node.h"
#include <vector>
#include "backpropagation.h"
class NetworkHandler
{
public:
    NetworkHandler();
    NetworkHandler(int inputNodeCount,int numberOfLayers,int numberOfNodes);
    void generateNodes();
    void PrettyPrint();
    void BackProp(float nn_output, float);
    float CalculateOutput(std::vector<int>);



private:
    std::vector<std::vector<Node>> nodes;
    double sigmoid(double x);

    int inputNodeCount = 0;
    int numberOfLayers = 0;
    int numberOfNodes = 0;

    float bias_weight[5][10];

    //output data logging
    float startlayer_outputs[500];
    float hiddenlayer_outputs[5][10];
};

#endif // NETWORKHANDLER_H
