#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H
#include <iostream>
#include "node.h"
#include <vector>
class NetworkHandler
{
public:
    NetworkHandler();
    NetworkHandler(int inputNodeCount,int numberOfLayers,int numberOfNodes);
    void generateNodes();
    void PrettyPrint();
private:
    std::vector<std::vector<Node>> nodes;

    int inputNodeCount;
    int numberOfLayers;
    int numberOfNodes;
};

#endif // NETWORKHANDLER_H
