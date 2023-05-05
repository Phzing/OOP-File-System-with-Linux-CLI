/*
* Lab 5
* File: RemoveCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in RemoveCommand.
*/

#include "mockos/RemoveCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void RemoveCommand::displayInfo() { //usage information for remove
    cout << "remove deletes a file from the filesystem, remove can be invoked with the command : rm <filename>" << endl;
}

int RemoveCommand::execute(string fileName) { //removes the given file by calling deleteFile()
    return fileSys->deleteFile(fileName);
}
