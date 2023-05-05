#pragma once

/*
* Lab 5
* File: TouchCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the TouchCommand class, which inherits the interface from AbstractCommand.
* Its purpose is to create a file.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>

using namespace std;

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
	AbstractFileFactory* fileFact;
public: 
	TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff);
	//virtual ~AbstractCommand();
	virtual void displayInfo() override;
	virtual int execute(std::string filename) override;
};