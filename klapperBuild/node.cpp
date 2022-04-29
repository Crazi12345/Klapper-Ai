#include "node.h"
#include <math.h>
#include <iostream>

// Constructors
Node::Node()
{

}

Node::Node(int row, int index){
    this->index = index;
    this->row =row;
}


//getters and setters
double Node::getWeight(int index) {
    return weights[index];
}
int Node::getIndex(){
    return index;
}

int Node::getRow(){
    return row;
}


//Calculate Funtions
void Node::calculateNewWeight(){

}


void Node::setweight(double input_weight, int index)
{
    if (index >= 0 && index <= 9) weights[index] = input_weight;

}









