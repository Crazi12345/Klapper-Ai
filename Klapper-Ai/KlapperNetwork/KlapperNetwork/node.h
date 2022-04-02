#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    Node(int row,int index);
    double getWeight();
    int getRow();
    int getIndex();


private:
double weight;
int row;
int index;

////
void calculateNewWeight();



};

#endif // NODE_H
