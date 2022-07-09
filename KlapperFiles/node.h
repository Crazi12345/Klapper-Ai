#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>
//#include "persistence.h"

class Node
{
public:
    Node();
    Node(int row,int index);
    double getWeight(int index);
    int getRow();
    int getIndex();
    std::string getId();
    void setWeight(double input_weight, int index);
    void loadWeight();


private:

int row;
int index;
double weights[10];

////
void calculateNewWeight();



};

#endif // NODE_H
