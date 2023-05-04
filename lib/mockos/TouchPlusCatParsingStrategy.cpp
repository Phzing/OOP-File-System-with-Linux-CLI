#include "mockos/TouchPlusCatParsingStrategy.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> TouchPlusCatParsingStrategy::parse(string inputs) {
	istringstream iss(inputs);
	vector<string> returnVec;
	string filename;
	iss >> filename;
	returnVec.push_back(filename);
	returnVec.push_back(filename);
	return returnVec;
}