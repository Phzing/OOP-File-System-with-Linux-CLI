#pragma once

/*
* Lab 5
* File: LSCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the LSCommand class. This command outputs the names of all files in the file system when invoked.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
#include <set>
using namespace std;

class LSCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
	int maxFileNameLength = 20;
public:
	LSCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};