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
    fileSys->closeFile(filePointer);
    filePointer = 0;
    if (addFilereturn == 0) {
        return 0; //success
    }
    delete copy; 
    return -3; // FIX HARDCODE file not added
}