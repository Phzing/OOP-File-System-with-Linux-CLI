#pragma once

/*
* Lab 5
* File: RenameParsingStrategy.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the RenameParsingStrategy class. It allows us to change the name of an existing file 
* as a MacroCommand.
*/

#include "mockos/AbstractParsingStrategy.h"
#include <string>
#include <vector>

using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) override;
};