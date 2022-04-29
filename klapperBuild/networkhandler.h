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
    void BackProp();
    float CalculateOutput(std::vector<int>);



private:
    std::vector<std::vector<Node>> nodes;

    int inputNodeCount;
    int numberOfLayers;
    int numberOfNodes;
};

#endif // NETWORKHANDLER_H
