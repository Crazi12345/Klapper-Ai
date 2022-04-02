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
    double σ(double x);
    double δ(double x, double y,int switcher);
    double f´σ(double x);
private:
    std::vector<std::vector<Node>> *nodes;


};




#endif // BACKPROPAGATION_H
