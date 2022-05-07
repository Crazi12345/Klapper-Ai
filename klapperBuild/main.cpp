#include <iostream>
#include "networkhandler.h"
#include <stdio.h>
#include <string.h>
#include <fstream>

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
    vector<int> input_nn(500, 1);
    input_nn.at(0) = 2;
    float output =  nh.CalculateOutput(input_nn);
    cout << output << endl;
    nh.BackProp(output, true);

    nh.PrettyPrint();


    return 0;
}
