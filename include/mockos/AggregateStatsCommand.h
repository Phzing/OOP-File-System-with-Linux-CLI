#pragma once

/*
* Lab 5
* File: AggregateStatsCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the AggregateStatsCommand class. Its purpose is to calculate and display aggregate statistics
* about our file system.
*/

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class AggregateStatsCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	AggregateStatsCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};