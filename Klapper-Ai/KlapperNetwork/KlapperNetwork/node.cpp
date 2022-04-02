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
double Node::getWeight() {
    return weight;
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

