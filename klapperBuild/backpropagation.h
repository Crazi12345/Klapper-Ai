#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include "node.h"
#include <vector>
class backpropagation
{
public:
    backpropagation( std::vector<std::vector<Node>> *nodes);
    void set_stepsize(float input_step);
    ////
    void backpropagate(float nn_output, float bias_weight);


private:
    double sigmoid(double x);
    double derivedSigmoid(double x);
    double delta(double x, double y,int switcher);
    float _stepsize = 1;
    std::vector<std::vector<Node>> *_nodes;


};






#endif // BACKPROPAGATION_H
