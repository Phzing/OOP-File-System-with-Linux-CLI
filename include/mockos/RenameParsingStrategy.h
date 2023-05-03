#pragma once
#include "mockos/AbstractParsingStrategy.h"
#include <string>
#include <vector>

using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) override;
};