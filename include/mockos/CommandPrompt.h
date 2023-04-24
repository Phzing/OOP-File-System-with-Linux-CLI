#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
#include <map>
class CommandPrompt{
    std::map<std::string, AbstractCommand *> commands;
    AbstractFileSystem * fileSys;
    AbstractFileFactory * fileFact;
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem *  afsPtr);
    void setFileFactory(AbstractFileFactory * affPtr);
    int addCommand(std::string command, AbstractCommand* acPtr);
    int run();

protected:
    void listCommands();
    std::string prompt();
};