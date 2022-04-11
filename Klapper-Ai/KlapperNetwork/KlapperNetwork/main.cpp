#include <iostream>
#include "networkhandler.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <pqxx/pqxx>
using namespace std;
using namespace pqxx;

int main()
{
connection* conn;
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


      connection C("dbname = isaac user = postgres password = Isaac hostaddr = 100.64.25.228 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }


/* Create SQL statement */
   //  sql = "DROP TABLE COMPANY";

     /* Create a transactional object. */
     work W(C);

     /* Execute SQL query */
     W.exec( sql );
     W.commit();
     cout << "Table dropped successfully" << endl;





    NetworkHandler nh(100,5,10);
    nh.generateNodes();
    nh.PrettyPrint();


    return 0;
}

