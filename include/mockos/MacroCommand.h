/*
#pragma once
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractParsingStrategy.h"
#include <vector>
#include <string>

using namespace std;

class MacroCommand : public AbstractCommand {
    vector<AbstractCommand> commands;
    AbstractParsingStrategy* absParsStratPtr;
public:
    MacroCommand();
    virtual void displayInfo() override;
    virtual int execute(string inputs) override;
    void addCommand(AbstractCommand* commandPtr);
    void setParseStrategy(AbstractParsingStrategy* ParsingStrategyPointer);
};
*/