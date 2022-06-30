#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include "node.h"
#include <vector>
#include <iostream>
class backpropagation
{
public:
    backpropagation( std::vector<std::vector<Node>> *nodes, float * output_inputLayer,
                     float * output_hiddenLayer, float * output_nn, float * b_weight);
    ~backpropagation();
    void set_stepsize(float input_step);
    ////
    void backpropagate(float);


private:
    float * _startlayer_outputs;
    float * _hiddenlayer_outputs; //double pointer casted to pointer
    float * _output_nn;
    float * _bias_weight;

    double sigmoid(double x);
    double derivedSigmoid(double x);
    double delta(double x, double y,int switcher);
    float _stepsize = 0.8;
    std::vector<std::vector<Node>> *_nodes;


};






#endif // BACKPROPAGATION_H
