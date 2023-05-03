#include "mockos/CopyCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void CopyCommand::displayInfo() {
    cout << "cp copies a file, cp can be invoked with the command : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string command) {
    istringstream iss(command);
    string originalFilename;
    iss >> originalFilename;
    AbstractFile* filePointer = fileSys->openFile(originalFilename);
    if (filePointer == nullptr) {
        cout << "file is nullptr" << endl;
        return -1; // FIX HARDCODE No file found in system
    }
    string copyName;
    string foo;
    if (!(iss>>copyName) || (iss>>foo)) {
        cout << "incorrect usage of cp" << endl;
        return -2; // FIX HARDCODE Incorrect command usage
    }
    
    AbstractFile* copy = filePointer->clone(copyName);
    int addFilereturn = fileSys->addFile(copy->getName(), copy);
    if (addFilereturn == 0) {
        return 0; //success
    }
    delete copy; 
    return -3; // FIX HARDCODE file not added
}

/*
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
    if (filePointer == nullptr) {
        cout << "file is nullptr" << endl;
        return -1; // No file found in system
    }
    if (space) {
        iss >> remString;
        if (remString == "-d") {
            vector<char> contents = filePointer->read();
            for (int i = 0; i < contents.size(); i++) {
                cout << contents[i];
            }
            cout << endl;
            fileSys->closeFile(filePointer);
            filePointer = 0;
            return 0; //Success FIX HARDCODE
        }
        cout << "Invalid usage of ds" << endl;
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return -2; // FIX HARDCODE
    }
    BasicDisplayVisitor displayVisitor;
    filePointer->accept(&displayVisitor);
    fileSys->closeFile(filePointer);
    filePointer = 0;
    return 0; //Success FIX HARDCODE
*/