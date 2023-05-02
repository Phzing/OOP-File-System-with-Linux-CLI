#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void LSCommand::displayInfo() {
    cout << "ls lists all files in a file system, ls can be invoked with the command : 'ls' (lists all files) OR 'ls -m' (all files with metadata)" << endl;
}

int LSCommand::execute(string command) {
    set<string> files = fileSys->getFileNames();
    if (command.size() == 0) {
        unsigned int filesPrinted = 0;
        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) {
            filesPrinted++;
            string filename = *it;
            cout << filename << flush;
            for (int i = filename.size(); i <= 20; ++i) { //FIX HARDCODE (set maxFilenameLength = 20)
                cout << " ";
            }
            if (filesPrinted % 2 == 0) { cout << endl; }
            else { cout << flush; }
        }
        return 0; // success (FIX HARDCODE)
    }
    else if (command.compare("-m") == 0) {
        MetadataDisplayVisitor MetadataDisplayVisitor;
        string fileType;
        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) {
            string filename = *it;
            cout << filename << flush;
            for (int i = filename.size(); i <= 20; ++i) { //FIX HARDCODE (set maxFilenameLength = 20)
                cout << " ";
            }
            AbstractFile* filePointer = fileSys->openFile(filename);
            //filePointer->accept(&MetadataDisplayVisitor); // this will print out the contents correctly for each file but not formatted correctly. To get it formatted correctly, used the following lines which could be replaced if we change the formatting in MetadataDispla...cpp
            string filetype;
            bool atDot = false;
            int dotPos = filename.find(".");
            dotPos++;
            filetype = filename.substr(dotPos);
            if (filetype.compare("txt") == 0) { fileType = "text"; }
            else if (filetype.compare("img") == 0) { fileType = "image"; }
            else { fileType = ""; }
            cout << fileType << flush;
            for (int i = fileType.size(); i <= 20; ++i) { //FIX HARDCODE (set maxFilenameLength = 20)
                cout << " ";
            }
            cout << filePointer->getSize() << endl;
            fileSys->closeFile(filePointer);
        }
        return 0; // success (FIX HARDCODE)
    }
    return -1; // FIX HARDCODE (invalid command)
}