#include "mockos/DisplayCommand.h"
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void DisplayCommand::displayInfo() {
    cout << "ds displays a file's contents, ds can be invoked with the command : ds <filename> [-d]" << endl;
}

int DisplayCommand::execute(string command) {
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
}
