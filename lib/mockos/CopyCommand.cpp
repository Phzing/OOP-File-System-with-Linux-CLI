/*
* Lab 5
* File: CopyCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions in CopyCommand.
*/

#include "mockos/CopyCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/enums.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void CopyCommand::displayInfo() { //usage information for cp
    cout << "cp copies a file, cp can be invoked with the command : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string command) { //executes the copy command when properly invoked
    istringstream iss(command);
    string originalFilename;
    iss >> originalFilename;
    AbstractFile* filePointer = fileSys->openFile(originalFilename);

    if (filePointer == nullptr) {
        cout << "file is nullptr" << endl;
        return returns::FILE_DOES_NOT_EXIST;
    }

    string copyName;
    string foo;

    if (!(iss>>copyName) || (iss>>foo)) {
        cout << "incorrect usage of cp" << endl;
        return returns::INVALID_CP_USE;
    }
    
    AbstractFile* copy = filePointer->clone(copyName); //copies the file by calling clone()
    int addFilereturn = fileSys->addFile(copy->getName(), copy);
    fileSys->closeFile(filePointer);
    filePointer = 0;

    if (addFilereturn == returns::SUCCESS) { //checks that file was properly added to the system
        return returns::SUCCESS;
    }

    delete copy; 
    return returns::FILE_NOT_ADDED; //file not added, deleted
}