#include "backpropagation.h"
#include <math.h>
#include "node.h"
backpropagation::backpropagation(std::vector<std::vector<Node>> *nodes, float * output_inputLayer, float * output_hiddenLayer, float * output_nn, float * b_weight)
{
    this->_nodes = nodes;

    this->_startlayer_outputs = output_inputLayer;
    this->_hiddenlayer_outputs = output_hiddenLayer;
    this->_output_nn = output_nn;
    this->_bias_weight = b_weight;


}

void backpropagation::set_stepsize(float input_step)
{
    _stepsize = input_step;
}

void backpropagation::backpropagate(bool clapSound)
{
    float control;
    switch((int)clapSound) {
    case true:
        control = 1.0;
        break;
    case false:
        control = 0.0;
        break;
    }

    for (int i = _nodes->size() - 1;  i >= 0; i--){
        float current_layer_sigma[10];
        float last_layer_sigma[10];


        for(int j = 0; j < _nodes->at(i).size(); j++){

            //sigma calculation
            if( i == (int)_nodes->size() - 1){
                current_layer_sigma[0] = (control - *_output_nn)*(*_output_nn-(1.0 - *_output_nn));
            }else{
                for(int sigma_count = 0; sigma_count < 10; sigma_count++){
                    float node_weight = _nodes->at(i).at(j).getWeight(sigma_count);

                    float output = _hiddenlayer_outputs[(i - 1)*10 + j]; //denne vil crashe når i er = 0,
                    float diferential_part = output*(1-output);//location from double array to single pointer


                    current_layer_sigma[sigma_count] = node_weight*last_layer_sigma[sigma_count]*diferential_part;
                }
            }





        }


    }


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
