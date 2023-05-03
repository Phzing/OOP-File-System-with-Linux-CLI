#pragma once
#include "mockos/AbstractCommand.h"
#include <vector>
#include <string>

class MacroCommand : public AbstractCommand{
    std::vector <AbstractCommand> commands;
    AbstractParsingStrategy * absParsStratPtr;

public:
    virtual void displayInfo() override;
    virtual int execute(std::string inputs);
    int addCommand();
};