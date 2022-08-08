#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <iostream>
#include "node.h"
#include <vector>
#include "backpropagation.h"
#include "persistence.h"

class NetworkHandler {
public:
	NetworkHandler();

	NetworkHandler(int inputNodeCount, int numberOfLayers, int numberOfNodes);

	void generateRandomWeightNodes();

	void generateNodes();

	std::vector<std::vector<Node>> getNodes();

	void PrettyPrint();

	void BackProp(float nn_output, float);

	void UpdateNeuralNetwork();

	float CalculateOutput(std::vector<int> &inputs);

	std::vector<float> getBiasWeight();
private:
	std::vector<std::vector<Node>> nodes;

	double sigmoid(double x);

	int inputNodeCount = 0;
	int numberOfLayers = 0;
	int numberOfNodes = 0;

	std::vector<float> bias_weight = {0,0,0,0,0,0};
	std::vector<float> bias_weight_change={0,0,0,0,0,0};

	void bias_weight_change_Clear();

	//output data logging
	float startlayer_outputs[500];
	float hiddenlayer_outputs[5][10];


	int batchAmount = 0;


};

#endif // NETWORKHANDLER_H
