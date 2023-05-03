#pragma once
#include <iostream>
#include "mockos/MacroCommand.h"
#include "mockos/AbstractCommand.h"
#include <vector>
#include <string>

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

int MacroCommand::execute(string inputs){
    vector<string> inputVect = absParsStratPtr->parse(inputs);
    for (int i = 0; i < commands.size(); i++){
        if (commands[i]->execute(inputVect[i]) != 0){
            return -5; //command failed
        }
    }
    return 0; //success
}

void MacroCommand:: displayInfo(){
    cout << "MacroCommand allows us to make commands that execute multiple commands in sequence from a single input string" << endl;
}

void MacroCommand::addCommand(AbstractCommand* commandPtr) {
    this->commands.push_back(commandPtr);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* ParsingStrategyPointer) {
    this->absParsStratPtr = ParsingStrategyPointer;
}