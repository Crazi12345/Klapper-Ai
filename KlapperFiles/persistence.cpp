#include "persistence.h"

Persistence::Persistence()
{

}

pqxx::connection Persistence::getConnection()
{
    pqxx::connection conn{"postgres://ymcbvebm:naW5cZI-1o7azsZk1QfAB3CrnMTni0We@abul.db.elephantsql.com/ymcbvebm"};
   return conn;
}

std::string Persistence::getConnectionString()
{
    return connectionString;
}

void Persistence::loadNode(std::string nodeId)
{

}

void Persistence::saveNodes(std::vector<std::vector<Node> > nodes)
{

}

void Persistence::moveTrainedData(int id)
{

}

