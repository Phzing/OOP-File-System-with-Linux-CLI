#pragma once

/*
* Lab 5
* File: CopyCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the CopyCommand class. Its purpose is to copy a file that exists in the system and add it to a
* file with a different name when it is invoked by cp.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

using namespace std;

class CopyCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	CopyCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};