#include <iostream>
#include "networkhandler.h"
using namespace std;

int main()
{
    NetworkHandler nh(100,5,10);
    nh.generateNodes();
    nh.PrettyPrint();
    return 0;
}
