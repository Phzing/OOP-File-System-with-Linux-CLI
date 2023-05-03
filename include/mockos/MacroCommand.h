#pragma once
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractParsingStrategy.h"
#include "mockos/AbstractFileSystem.h"
#include <vector>
#include <string>

using namespace std;

class MacroCommand : public AbstractCommand {
    vector<AbstractCommand*> commands;
    AbstractParsingStrategy* absParsStratPtr{};
    AbstractFileSystem* fileSys;
public:
    MacroCommand(AbstractFileSystem* afs);
    virtual void displayInfo() override;
    virtual int execute(string inputs) override;
    void addCommand(AbstractCommand* commandPtr);
    void setParseStrategy(AbstractParsingStrategy* ParsingStrategyPointer);
};