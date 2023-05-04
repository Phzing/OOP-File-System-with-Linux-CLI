#pragma once
#include <string>
#include <vector>

using namespace std;

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) = 0;
};