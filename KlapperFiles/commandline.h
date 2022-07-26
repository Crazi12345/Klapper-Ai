#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <iostream>
#include "networkhandler.h"
#include "traininghandler.h"
class CommandLine
{
public:
    CommandLine();

    void Help();
    void Menu();
    void CommandHandler(std::string command);
    void Clear();
    void Exit();
};

#endif // COMMANDLINE_H
