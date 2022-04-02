#include "node.h"
#include <math.h>
#include <iostream>
Node::Node()
{
std::cout << sigmoid(10000.0) << std::endl;
}


double Node::getWeight() {
    return weight;
}

void Node::calculateNewWeight(){



}


double Node::sigmoid(double x){

    return(1/(1+pow(2.71828,-1.0*x)));
}

double Node::σ(double x)
{

}
