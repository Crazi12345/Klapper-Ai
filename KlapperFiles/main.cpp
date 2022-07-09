#include <iostream>
#include "networkhandler.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#include "persistence.h"
#include <pqxx/pqxx>
#include "traininghandler.h"

using namespace std;
int main()
{



    //srand((unsigned) time(0));

    NetworkHandler nh(500,5,10);
    nh.generateNodes();
    //nh.generateRandomWeightNodes();

    TrainingHandler trainer(nh);
    trainer.GenerateInputNodes();
    trainer.Train();


    return 0;
}



