/*
* Lab 5
* File: DisplayCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions in DisplayCommand.
*/

#include "mockos/DisplayCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/enums.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void DisplayCommand::displayInfo() { //usage information for ds
    cout << "ds displays a file's contents, ds can be invoked with the command : ds <filename> [-d]" << endl;
}

int DisplayCommand::execute(string command) { //executes ds when invoked properly
    bool space = false;

    for (int i = 0; i < command.size(); i++) {
        if (command[i] == ' ') {
            space = true;
        }
    }

    istringstream iss(command);
    string filename;
    string remString;
    iss >> filename;
    AbstractFile* filePointer = fileSys->openFile(filename);

    if (filePointer == nullptr) { //checks that file is in the system
        cout << "file is nullptr" << endl;
        return returns::FILE_DOES_NOT_EXIST; 
    }

    if (space) {
        iss >> remString;
        if (remString == "-d") { //data only displayed, unformatted 
            vector<char> contents = filePointer->read();
            for (int i = 0; i < contents.size(); i++) {
                cout << contents[i];
            }
            cout << endl;
            fileSys->closeFile(filePointer);
            filePointer = 0;
            return returns::SUCCESS; 
        }
        cout << "Invalid usage of ds" << endl; //unsupported functionality given
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return returns::INVALID_DS_USE;
    }

    BasicDisplayVisitor displayVisitor; //formatted data display
    filePointer->accept(&displayVisitor);
    fileSys->closeFile(filePointer);
    filePointer = 0;
    return returns::SUCCESS;
}
