#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    Node(int row,int index);
    double getWeight(int index);
    int getRow();
    int getIndex();
    double sigmoid(double x);
    void setweight(double, int);


private:

int row;
int index;
double weights[10];

////
void calculateNewWeight();



};

#endif // NODE_H
