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

backpropagation::~backpropagation()
{

}

void backpropagation::set_stepsize(float input_step)
{
    _stepsize = input_step;
}

void backpropagation::backpropagate(float clapSound)
{


    float control = clapSound;


    float current_layer_sigma[10];
    for(int i = 0; i < 10; i++){
        current_layer_sigma[i] = 0;
    }

    float last_layer_sigma[10];

    for (int i = _nodes->size() - 1;  i >= 0; i--){

        for(int array_index = 0; array_index < 10; array_index++){
            last_layer_sigma[array_index] = current_layer_sigma[array_index];
        }


        float output = 0;

        for(int j = 0; j < _nodes->at(i).size(); j++){
            
            float out;
            out = _startlayer_outputs[37];


            //sigma calculation
            if( i == (int)_nodes->size() - 1){
                current_layer_sigma[0] = (control - *_output_nn)*(*_output_nn * (1 - *_output_nn));
                continue; // if output layer, then no more should be done.

            }else if(i != 0){ //Sigma should not be calculated for the starting layers

                float node_weight;
                float dif_Times_Weight = 0;
                int sigma_size;

                if(i == (int)_nodes->size() - 2){
                    sigma_size = 1;
                }else{
                    sigma_size = 10;
                }

                for(int sigma_count = 0; sigma_count < sigma_size; sigma_count++){
                    node_weight = _nodes->at(i).at(j).getWeight(sigma_count);
                    dif_Times_Weight += node_weight * last_layer_sigma[sigma_count];

                }

                output = _hiddenlayer_outputs[(i - 1)*10 + j];


                float diferential_part = output*(1 - output);//location from double array to single pointer


                current_layer_sigma[j] = dif_Times_Weight*diferential_part;

            }

            if(i == 0){// if starting layer
                output = _startlayer_outputs[j];
            }


            //calculate all weight changes and find the average value.


            int weight_count;
            if(i == ((int)_nodes->size() - 2)){
                weight_count = 1;
            }else{
                weight_count = 10;
            }


            if( j == 0){
                for(int bias_weight_index = 0; bias_weight_index < weight_count; bias_weight_index++){
                    //Calculcate bias weight

                    _bias_weight[i*10 + bias_weight_index] = _bias_weight[i*10 + bias_weight_index] + (_stepsize * last_layer_sigma[bias_weight_index] * _bias_weight[i*10 + bias_weight_index] ); //The bias output is 1. -> nonexistent
                }
            }



            for(int weights_index = 0; weights_index < weight_count; weights_index++){
                float weight_difference = _stepsize * last_layer_sigma[weights_index] * output;

                float weight_current = _nodes->at(i).at(j).getWeight(weights_index);

                _nodes->at(i).at(j).setweight(weight_current + weight_difference, weights_index);


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
