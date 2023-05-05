/*
* Lab 5
* File: TouchPlysCatParsingStrategy.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used to invoke our macro command which invokes touch and then cat.
*/

#include "mockos/TouchPlusCatParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> TouchPlusCatParsingStrategy::parse(string inputs) { //parses the input for the macro command
	istringstream iss(inputs);
	vector<string> returnVec;
	string filename;
	iss >> filename;
	returnVec.push_back(filename); //touch
	returnVec.push_back(filename); //cat
	return returnVec;
}