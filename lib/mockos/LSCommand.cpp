/*
* Lab 5
* File: LSCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in LSCommand.
*/

#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include "mockos/enums.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void LSCommand::displayInfo() { //contains usage information for ls
    cout << "ls lists all files in a file system, ls can be invoked with the command : 'ls' (lists all files) OR 'ls -m' (all files with metadata)" << endl;
}

int LSCommand::execute(string command) { //executes the ls command when properly invoked
    set<string> files = fileSys->getFileNames();

    if (command.size() == 0) { //displays all file names
        unsigned int filesPrinted = 0;

        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) { //iterates through files
            filesPrinted++;
            string filename = *it;
            cout << filename << flush;

            for (int i = filename.size(); i <= maxFileNameLength; ++i) { 
                cout << " ";
            }

            if (filesPrinted % 2 == 0) { cout << endl; }

            else { cout << flush; }
        }
        return returns::SUCCESS;
    }

    else if (command.compare("-m") == 0) { //support for displaying metadata associated with each file
        MetadataDisplayVisitor MetadataDisplayVisitor;
        string fileType;

        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) { //iterates through all files
            string filename = *it;
            cout << filename << flush;

            for (int i = filename.size(); i <= maxFileNameLength; ++i) {
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

            for (int i = fileType.size(); i <= maxFileNameLength; ++i) { 
                cout << " ";
            }

            cout << filePointer->getSize() << endl;
            fileSys->closeFile(filePointer);
        }
        return returns::SUCCESS;
    }
    return returns::INVALID_COMMAND;
}