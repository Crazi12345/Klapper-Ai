#include "node.h"
#include <math.h>
#include <iostream>
#include "persistence.h"
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

// ID For database
std::string Node::getId(){
    std::string fname = std::to_string(row);
    std::string lname = std::to_string(index);
    return fname+":"+lname;
}

//Calculate Funtions
void Node::calculateNewWeight(){

}


void Node::setWeight(double input_weight, int index)
{
 if (index >= 0 && index <= 9) weights[index] = input_weight;

}

void Node::loadWeight(){
    Persistence p;
    std::vector<long> newWeight = p.loadNode(this->getId());

    for(int i = 0; i<newWeight.size();i++){

        weights[i] = newWeight[i];
    }
}







