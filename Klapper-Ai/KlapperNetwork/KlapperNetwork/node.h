#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    double getWeight();


private:
double weight;
void calculateNewWeight();
double sigmoid(double x);
double σ(double x);

};

#endif // NODE_H
