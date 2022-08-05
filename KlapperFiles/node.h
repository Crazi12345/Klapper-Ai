#ifndef NODE_H
#define NODE_H

#include <string.h>
#include <iostream>
#include <vector>

class Node {
public:
	Node();

	Node(int row, int index);

	double getWeight(int index);

	int getRow();

	int getIndex();

	std::string getId();

	void CommitAVGWeightChange(int samples);

	void setRandomWeight(int numberSpan, int index);

	void AddNewWeightChange(double input_weight, int index);

	void resetWeightchange();

	void loadWeight(std::vector<long>);


private:

	int row;
	int index;
	double weights[10];
	double weightsChange[10];


};

#endif // NODE_H
