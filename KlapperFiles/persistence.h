#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <iostream>
#include <pqxx/pqxx>
#include "node.h"
class Persistence
{
public:
    Persistence(std::vector<std::vector<Node>> nodes);
    pqxx::connection getConnection();
    std::string getConnectionString();
    void loadNode(std::string nodeId);
    void saveNodes();
    void generateFreshNodes();
    void moveTrainedData(int id);


private:
    std::string connectionString = "postgres://ymcbvebm:naW5cZI-1o7azsZk1QfAB3CrnMTni0We@abul.db.elephantsql.com/ymcbvebm";
    std::string generateWeightQueryString(int nodeX, int nodeY);
    std::vector<std::vector<Node>> nodes;

};

#endif // PERSISTENCE_H
