#include <iostream>
#include "networkhandler.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>
#include "persistence.h"
#include <pqxx/pqxx>


using namespace std;
int main()
{
    Persistence persistence;
    srand((unsigned) time(0));
try{
    pqxx::connection conn = persistence.getConnection();
    pqxx::work db{conn};
    cout << "connected" <<endl;
}
    catch(exception e){
        cout << e.what()<< endl;
    }

    NetworkHandler nh(500,5,10);
    nh.generateNodes();

    vector<int> input_nn1(500);
    vector<int> input_nn2(500);



    for(int i = 0; i < 500; i++){

        input_nn1.at(i) = 10;
        input_nn2.at(i) = 0;
    }

    //Training
    int train_count = 5000;
    int max_fails = 10;
    float precision = 0.2;
    float input1;
    float input2;

    for(int fails = 0; fails < max_fails; fails++){


        //First phase training
        for(int train_cycles = 0; train_cycles < train_count + 1; train_cycles++){
            input1 = nh.CalculateOutput(input_nn1);
            input2 = nh.CalculateOutput(input_nn2);

            nh.BackProp(input1, 1);
            nh.BackProp(input2, 0);


            if(train_cycles%(train_count/10) == 0){
                float val = train_cycles*100;
                float val2 = train_count;
                cout << "LOADING: " << (val/val2) << "%" << endl;
            }
        }


        input1 = nh.CalculateOutput(input_nn1);
        input2 = nh.CalculateOutput(input_nn2);

        if ( (input1 < (1 + precision) && input1 > (1 - precision)) && (input2 < (precision) && input1 > ( -precision))){
            fails = max_fails;
            cout << "TRAINING SECOND PHASE:" << endl;
            cout << "TARGET: " << input1 << endl;
            cout << "NOICE: " << input2 << endl;


            int phase_2_train_count = train_count*10;

            for(int train_cycles = 0; train_cycles < phase_2_train_count + 1; train_cycles++){
                input1 = nh.CalculateOutput(input_nn1);
                input2 = nh.CalculateOutput(input_nn2);

                nh.BackProp(input1, 1);
                nh.BackProp(input2, 0);
                if(train_cycles%(phase_2_train_count/10) == 0){
                    float val = train_cycles*100;
                    float val2 = phase_2_train_count;
                    cout << "LOADING: " << (val/val2) << "%" << endl;
                }
            }

            cout << "TARGET: " << input1 << endl;
            cout << "NOICE: " << input2 << endl;
        }else{
            cout << "NETWORK FAILED: RETRY" << endl;
            cout << "TARGET: " << input1 << endl;
            cout << "NOICE: " << input2 << endl;

            srand((unsigned) time(0));
            nh = NetworkHandler(500,3,5);
            nh.generateNodes();


        }


    }
  nh.PrettyPrint();

    return 0;
}



