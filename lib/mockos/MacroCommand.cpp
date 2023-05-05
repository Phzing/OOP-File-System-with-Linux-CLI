/*
* Lab 5
* File: MacroCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in MacroCommand.
*/

#include <iostream>
#include "mockos/MacroCommand.h"
#include "mockos/AbstractCommand.h"
#include <vector>
#include <string>
#include "mockos/enums.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

int MacroCommand::execute(string inputs){ //executes a macro command by calling each individual command given in order
    vector<string> inputVect = absParsStratPtr->parse(inputs); //calls a parsing strategy to parse the input provided
    for (int i = 0; i < commands.size(); i++){
        if (commands[i]->execute(inputVect[i]) != 0){
            return returns::COMMAND_FAIL; //a command failed
        }
    }
    return returns::SUCCESS; 
}

void MacroCommand:: displayInfo(){ //usage info for a macro command
    cout << "MacroCommand allows us to make commands that execute multiple commands in sequence from a single input string" << endl;
}

void MacroCommand::addCommand(AbstractCommand* commandPtr) { //adds a given command to the vector
    this->commands.push_back(commandPtr);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* ParsingStrategyPointer) { //sets the macro command's parsing strategy
    this->absParsStratPtr = ParsingStrategyPointer;
}