#include "mockos/RemoveCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void RemoveCommand::displayInfo() {
    cout << "remove deletes a file from the filesystem, remove can be invoked with the command : rm <filename>" << endl;
}

int RemoveCommand::execute(string fileName) {
    return fileSys->deleteFile(fileName);
}
