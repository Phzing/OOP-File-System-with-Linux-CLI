#pragma once

/*
* Lab 5
* File: CommandPrompt.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class CommandPrompt. This is what handles user input and output.
*/

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
    ~CommandPrompt();
    void setFileSystem(AbstractFileSystem *  afsPtr);
    void setFileFactory(AbstractFileFactory * affPtr);
    int addCommand(std::string command, AbstractCommand* acPtr);
    int run();
protected:
    void listCommands();
    std::string prompt();
};