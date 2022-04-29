#include "backpropagation.h"
#include <math.h>
#include "node.h"
backpropagation::backpropagation(std::vector<std::vector<Node>> *nodes)
{
    this->_nodes = nodes;




}

void backpropagation::set_stepsize(float input_step)
{
    _stepsize = input_step;
}

void backpropagation::backpropagate(float nn_output, float bias_weight)
{



}

double backpropagation::sigmoid(double x){

    return(1/(1+pow(2.71828,-1*x)));
}
double backpropagation::derivedSigmoid(double x){
    return sigmoid(x)*(1-sigmoid(x));
}

double backpropagation::delta(double x, double y,int switcher){
    int control = 1;
    switch(switcher)  {
    case 0:
        return(control-y)*(y*(1-y));
        break;
    case 1:
        return 1;
        break;
    default:
        return -1;
    }
    return -1;
}
