/*
* Lab 5
* File: TouchCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in TouchCommand.
*/

#include "mockos/TouchCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
#include "mockos/enums.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff) {
    fileSys = afs;
    fileFact = aff;
}

void TouchCommand::displayInfo() { //usage information for the touch command
    cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}

int TouchCommand::execute(string command) { //creates a file with the given name through the file factory
    bool space = false;
    for (int i = 0; i < command.size(); i++) {
        if (command[i] == ' ') {
            space = true;
        }
    }
    if(space == false) {
        AbstractFile *file = fileFact->createFile(command);
        if (file == nullptr) { //checks if createFile() failed
            return returns::NO_FILE_CREATED;
        }
        int addFilereturn = fileSys->addFile(command, file);
        if (addFilereturn == 0) {
            return returns::SUCCESS; 
        }
        delete file;
        return returns::FILE_NOT_ADDED; //file not properly added, deleted
    }
    else{
        istringstream iss(command);
        string word1;
        string remString;
        string pass;
        iss >> word1;
        iss >> remString;
        if (remString == "-p"){ //requests a password for a password protected file
            cout << "What is the password?" << endl;
            cin >> pass;
            AbstractFile *file = fileFact->createFile(word1);
            if (file == nullptr) {
                return returns::NO_FILE_CREATED;
            }
            PasswordProxy * passwordFile = new PasswordProxy(file, pass);
            int addFilereturn = fileSys->addFile(word1, passwordFile);
            if (addFilereturn == returns::SUCCESS) {
                return returns::SUCCESS;
            }
            delete file;
            return returns::FILE_NOT_ADDED; //file not added properly, deleted
        }
        return returns::INVALID_COMMAND; //invalid usage of touch command
    }
}

