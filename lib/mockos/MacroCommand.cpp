#pragma once
#include <iostream>
#include "mockos/MacroCommand.h"


using namespace std;

//MacroCommand::MacroCommand() {
//}

int MacroCommand:: execute(string inputs){
    vector <string> inputVect = absParsStratPtr->parse(inputs);
    for (int i = 0; i < commands.size(); i++){
        if (commands[i].execute(inputVect[i]) != 0){
            return -5; //command failed
        }
    }
    return 0; //success
}

void MacroCommand:: displayInfo(){

}

int MacroCommand::addCommand(AbstractCommand * ) {
    //todo: Implement
}