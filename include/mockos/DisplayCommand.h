#pragma once

/*
* Lab 5
* File: DisplayCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the DisplayCommand class. Its purpose is to open a file and display its contents when invoked by ds.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	DisplayCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};