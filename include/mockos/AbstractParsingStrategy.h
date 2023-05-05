#pragma once

/*
* Lab 5
* File: AbstractParsingStrategy.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the interface for a parsing strategy.
*/

#include <string>
#include <vector>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) = 0;
};