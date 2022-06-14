#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <iostream>
#include <pqxx/pqxx>
#include "node.h"
class Persistence
{
public:
    Persistence();
    pqxx::connection getConnection();
    std::string getConnectionString();
    void loadNode(std::string nodeId);
    void saveNodes(std::vector<std::vector<Node>> nodes);
    void moveTrainedData(int id);


private:
    std::string connectionString = "postgres://ymcbvebm:naW5cZI-1o7azsZk1QfAB3CrnMTni0We@abul.db.elephantsql.com/ymcbvebm";


};

#endif // PERSISTENCE_H
