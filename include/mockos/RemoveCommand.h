#pragma once

/*
* Lab 5
* File: RemoveCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class RemoveCommand. The purpose of this command is to remove a given file from the system.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

using namespace std;

class RemoveCommand : public AbstractCommand {
    AbstractFileSystem* fileSys;
public:
    RemoveCommand(AbstractFileSystem* afs);
    //virtual ~AbstractCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string filename) override;
};