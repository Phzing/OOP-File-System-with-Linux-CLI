#pragma once

/*
* Lab 5
* File: TouchPlusCatParsingStrategy.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class TouchPlusCatParsingStrategy. It is a macro command which allows us to create
* a file and immediately edit it by invoking touch and then cat.
*/

#include "mockos/AbstractParsingStrategy.h"
#include <string>
#include <vector>

using namespace std;

class TouchPlusCatParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) override;
};