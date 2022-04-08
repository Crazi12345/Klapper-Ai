#include <iostream>
#include "networkhandler.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <pqxx/pqxx>
using namespace std;
using namespace pqxx;

int main()
{
connection* conn;
   string sql;

      connection C("dbname = isaac user = postgres hostaddr = 192.168.0.104 port = 5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }


/* Create SQL statement */
     sql = "DROP TABLE COMPANY";

     /* Create a transactional object. */
     work W(C);

     /* Execute SQL query */
     W.exec( sql );
     W.commit();
     cout << "Table dropped successfully" << endl;




   //  connection = sqlite3_open(location,&DB);
/*

    NetworkHandler nh(100,5,10);
    nh.generateNodes();
    nh.PrettyPrint();
    */

    return 0;
}

