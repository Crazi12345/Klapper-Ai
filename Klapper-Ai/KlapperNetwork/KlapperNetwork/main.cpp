#include <iostream>
#include "networkhandler.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{   const char* location = "database.db";
    sqlite3* DB;
    int connection = 0;
   //  connection = sqlite3_open(location,&DB);

    if(connection){
        cout << "Connected" << endl;
    }
    else{
        cout << "could not connect" << endl;
    }
    NetworkHandler nh(100,5,10);
    nh.generateNodes();
    nh.PrettyPrint();
    return 0;
}
