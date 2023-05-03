#pragma once
#include <string>
#include <vector>

using namespace std;

class AbstractParsingStrategy {
public:
	AbstractParsingStrategy();
	virtual vector<string> parse(string inputs) = 0;
	~AbstractParsingStrategy();
};