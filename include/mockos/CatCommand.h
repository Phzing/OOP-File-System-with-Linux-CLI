#pragma once

/*
* Lab 5
* File: CatCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the CatCommand class. This command concatenates and writes files.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class CatCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	CatCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};