#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>
class Node
{
public:
    Node();
    Node(int row,int index);
    double getWeight(int index);
    int getRow();
    int getIndex();
    std::string getId();
    void setweight(double, int);


private:

int row;
int index;
double weights[10];

////
void calculateNewWeight();



};

#endif // NODE_H
