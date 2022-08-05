#include "node.h"
#include <math.h>
#include <iostream>

// Constructors
Node::Node() {

}

Node::Node(int row, int index) {
	resetWeightchange();
	this->index = index;
	this->row = row;

}


//getters and setters
double Node::getWeight(int index) {
	return weights[index];
}

int Node::getIndex() {
	return index;
}

int Node::getRow() {
	return row;
}

// ID For database
std::string Node::getId() {
	std::string fname = std::to_string(row);
	std::string lname = std::to_string(index);
	return fname + ":" + lname;
}


void Node::AddNewWeightChange(double input_weight, int index) {
	if(index >= 0 && index <= 9) weightsChange[index] += input_weight;

}


void Node::resetWeightchange() {

	for(int i = 0; i < 10; i++) {
		weightsChange[i] = 0;
	}

}

void Node::setRandomWeight(int numberSpan, int index) {

	float random_weight = (rand() % (numberSpan) - numberSpan / 2);
	weights[index] = random_weight;
}


void Node::CommitAVGWeightChange(int samples) {

	for(int i = 0; i < 10; i++) {

		weightsChange[i] /= samples;
		weights[i] += weightsChange[i];
		weightsChange[i] = 0;

	}

}

void Node::loadWeight(std::vector<long> newWeight) {


	for(int i = 0; i < newWeight.size(); i++) {

		weights[i] = newWeight[i];
	}
}







