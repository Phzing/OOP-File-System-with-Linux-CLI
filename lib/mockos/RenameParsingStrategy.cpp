/*
* Lab 5
* File: RenameParsingStrategy.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions for RenameParsingStrategy.
*/

#include "mockos/RenameParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "mockos/enums.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string inputs) { //parses through the given macro command to create a vector containing information for the copy command and the remove command
	istringstream iss(inputs);
	vector<string> returnVec;
	string existingFilename;
	string newName;
	iss >> existingFilename;
	iss >> newName;
	returnVec.push_back(existingFilename + " " + newName); //for copy
	returnVec.push_back(existingFilename); //for remove
	return returnVec;
}