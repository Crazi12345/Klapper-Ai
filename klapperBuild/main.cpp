#include <iostream>
#include "networkhandler.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
int main()
{

    string sql;
    fstream file;
    file.open ("databaseConfig.txt", ios::in );
    if(!file){
        cout << "File not found "<<endl;
    }else {
        char ch;


        while (1) {
            file >> ch;
            if (file.eof())
                break;

            cout << ch;
        }

    }
    file.close();

    NetworkHandler nh(500,5,10);
    nh.generateNodes();

    vector<int> input_nn1(500);
    vector<int> input_nn2(500);
    vector<int> input_nn3(500);
    vector<int> input_nn4(500);
    vector<int> input_nn5(500);
    vector<int> input_nn6(500);
    vector<int> input_nn7(500);
    vector<int> input_nn8(500);
    vector<int> input_nn9(500);
    vector<int> input_nn10(500);
    vector<int> input_nn11(500);


    for(int i = 0; i < 500; i++){
        input_nn1.at(i) = 0;
        input_nn2.at(i) = 1;
        input_nn3.at(i) = 3;
        input_nn4.at(i) = 3;
        input_nn5.at(i) = 4;
        input_nn6.at(i) = 5;
        input_nn7.at(i) = 6;
        input_nn8.at(i) = 7;
        input_nn9.at(i) = 8;
        input_nn10.at(i) = 9;
        input_nn11.at(i) = i;
}


    float input_1;
    float input_2;
    float input_3;
    float input_4;
    float input_5;
    float input_6;
    float input_7;
    float input_8;
    float input_9;
    float input_10;
    float input_11;

    int training_cycles = 100;

    for(int train_count = 0; train_count < training_cycles; train_count++){



        //Train to hit a specific value disregarding the vector

//        rand_nr.clear();
//        for(int i = 0; i < 500; i++){
//            rand_nr.push_back(rand()%100);
//        }
//        float control = 0.3;

//        float output =  nh.CalculateOutput(rand_nr);
//        nh.BackProp(output, control);

//        if(train_count%1000 == 0){
//            cout << "CONTROL: " << control << " - output: " << output << endl;
//        }



        //Train to differentiate between two reversed indexes



        input_1 =  nh.CalculateOutput(input_nn1);
        nh.BackProp(input_1, 1);

        input_2 =  nh.CalculateOutput(input_nn2);
        nh.BackProp(input_2, 0.9);

        input_3 =  nh.CalculateOutput(input_nn3);
        nh.BackProp(input_3, 0.8);

        input_4 =  nh.CalculateOutput(input_nn4);
        cout << "output: " << input_4 << endl;
        nh.BackProp(input_4, 0.7);

        input_5 =  nh.CalculateOutput(input_nn5);
        nh.BackProp(input_5, 0.6);

        input_6 =  nh.CalculateOutput(input_nn6);
        nh.BackProp(input_6, 0.5);

        input_7 =  nh.CalculateOutput(input_nn7);
        nh.BackProp(input_7, 0.4);

        input_8 =  nh.CalculateOutput(input_nn8);
        nh.BackProp(input_8, 0.3);

        input_9 =  nh.CalculateOutput(input_nn9);
        nh.BackProp(input_9, 0.2);

        input_10 =  nh.CalculateOutput(input_nn10);
        nh.BackProp(input_10, 0.1);

        input_11 =  nh.CalculateOutput(input_nn11);
        nh.BackProp(input_11, 0.069);


        if(train_count%(training_cycles/10) == 0){
            cout << "LOADING: " << train_count/((training_cycles/100)) << "%" << endl;
        }
    }




    cout << "RESULT:" << endl;

    cout << "control: 1 - output: " <<  nh.CalculateOutput(input_nn1) << endl;
    cout << "control: 0.9 - output: " <<  nh.CalculateOutput(input_nn2) << endl;
    cout << "control: 0.8 - output: " <<  nh.CalculateOutput(input_nn3) << endl;
    cout << "control: 0.7 - output: " <<  nh.CalculateOutput(input_nn4) << endl;
    cout << "control: 0.6 - output: " <<  nh.CalculateOutput(input_nn5) << endl;
    cout << "control: 0.5 - output: " <<  nh.CalculateOutput(input_nn6) << endl;
    cout << "control: 0.4 - output: " <<  nh.CalculateOutput(input_nn7) << endl;
    cout << "control: 0.3 - output: " <<  nh.CalculateOutput(input_nn8) << endl;
    cout << "control: 0.2 - output: " <<  nh.CalculateOutput(input_nn9) << endl;
    cout << "control: 0.1 - output: " <<  nh.CalculateOutput(input_nn10) << endl;
    cout << "control: 0.0 - output: " <<  nh.CalculateOutput(input_nn11) << endl;

    return 0;
}
