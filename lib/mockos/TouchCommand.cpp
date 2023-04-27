#include "mockos/TouchCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff) {
    fileSys = afs;
    fileFact = aff;
}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command : touch <filename>" << endl;
}

int TouchCommand::execute(string filename) {
    AbstractFile* file = fileFact->createFile(filename);
    if (file == nullptr) {
        return -1; //fix hardcode - no file created
    }
    int addFilereturn = fileSys->addFile(filename, file);
    if (addFilereturn == 0) {
        return 0; //success
    }
    delete file;
    return -2; // FIX HARDCODE - file not added, deleted
}

