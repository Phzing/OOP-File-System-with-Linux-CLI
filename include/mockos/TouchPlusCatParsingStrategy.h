#pragma once
#include "mockos/AbstractParsingStrategy.h"
#include <string>
#include <vector>

using namespace std;

class TouchPlusCatParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string inputs) override;
};