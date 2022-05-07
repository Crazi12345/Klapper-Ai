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
    void BackProp(float nn_output, bool);
    float CalculateOutput(std::vector<int>);



private:
    std::vector<std::vector<Node>> nodes;
    double sigmoid(double x);

    int inputNodeCount = 0;
    int numberOfLayers = 0;
    int numberOfNodes = 0;

    float bias_input = 1;
    float bias_weight = 1;

    //output data logging
    float * startlayer_outputs;
    float * hiddenlayer_outputs;
};

#endif // NETWORKHANDLER_H
