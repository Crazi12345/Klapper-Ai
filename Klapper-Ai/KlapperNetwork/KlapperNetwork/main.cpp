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

    NetworkHandler nh(100,5,10);
    nh.generateNodes();
    nh.PrettyPrint();


    return 0;
}
