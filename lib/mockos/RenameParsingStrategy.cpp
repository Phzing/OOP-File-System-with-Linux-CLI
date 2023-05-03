#include "mockos/RenameParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string inputs) {
	istringstream iss(inputs);
	vector<string> returnVec;
	string existingFilename;
	string newName;
	iss >> existingFilename;
	iss >> newName;
	returnVec.push_back(existingFilename + " " + newName);
	returnVec.push_back(existingFilename);
	return returnVec;
}