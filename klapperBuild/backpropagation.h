#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include "node.h"
#include <vector>
class backpropagation
{
public:
    backpropagation( std::vector<std::vector<Node>> *nodes);

    double sigmoid(double x);
    double derivedSigmoid(double x);
    double delta(double x, double y,int switcher);
    ////

private:
    std::vector<std::vector<Node>> *nodes;


};




#endif // BACKPROPAGATION_H
