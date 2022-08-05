#ifndef TRAININGHANDLER_H
#define TRAININGHANDLER_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "networkhandler.h"

class TrainingHandler {
public:
	TrainingHandler();

	TrainingHandler(NetworkHandler);

	void GenerateInputNodes();

	void Train();

private:
	NetworkHandler nh;
	std::vector<int> input_nn1;
	std::vector<int> input_nn2;

	int train_count = 5000;
	int max_fails = 10;
	float precision = 0.2;
	float input1;
	float input2;

};

#endif // TRAININGHANDLER_H
