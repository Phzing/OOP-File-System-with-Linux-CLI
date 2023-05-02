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

int TouchCommand::execute(string command) {
    bool space = false;
    for (int i = 0; i < command.size(); i++) {
        if (command[i] == ' ') {
            space = true;
        }
    }
    if(space == false) {
        AbstractFile *file = fileFact->createFile(command);
        if (file == nullptr) {
            return -1; //fix hardcode - no file created
        }
        int addFilereturn = fileSys->addFile(command, file);
        if (addFilereturn == 0) {
            return 0; //success
        }
        delete file;
        return -2; // FIX HARDCODE - file not added, deleted
    }
    else{
        istringstream iss(command);
        string word1;
        string remString;
        string pass;
        iss >> word1;
        iss >> remString;
        if (remString == "-p"){
            cout << "What is the password?" << endl;
            cin >> pass;
            //TODO: implement password proxy creation with pass
        }
        return -1; //FIX HARDCODE Command does not exist
    }
}

