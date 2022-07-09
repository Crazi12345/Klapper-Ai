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
    std::vector<long> loadNode(std::string nodeId);
    void saveNodes(std::vector<std::vector<Node>> nodes);
    void generateFreshNodes(std::vector<std::vector<Node>> nodes);
    void moveTrainedData(int id);
    void loadNodeData();


private:
    std::string connectionString =
            "postgres://ymcbvebm:naW5cZI-1o7azsZk1QfAB3CrnMTni0We@abul.db.elephantsql.com/ymcbvebm";
    std::string generateWeightQueryString(
            int nodeX, int nodeY,std::vector<std::vector<Node>> nodes);

    pqxx::result nodeData;
    int iterator = 0;
    int iterationNum = 0;

};

#endif // PERSISTENCE_H
