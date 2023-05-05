/*
* Lab 5
* File: AggregateStatsCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions in AggregateStatsCommand.
*/

#include "mockos/AggregateStatsCommand.h"
#include "mockos/AggregateStatisticsVisitor.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include "mockos/enums.h"
#include <string>
#include <iterator>

using namespace std;

AggregateStatsCommand::AggregateStatsCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void AggregateStatsCommand::displayInfo() { //usage information for as
    cout << "as displays the file system's aggregate statistics, as can be invoked with the command : as" << endl;
}

int AggregateStatsCommand::execute(std::string command) {
    set<string> files = fileSys->getFileNames();
    if (command.size() == 0) { //checks that command was passed in properly
        AggregateStatisticsVisitor asVisitor;
        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) { //iterates through files
            AbstractFile* filePointer = fileSys->openFile(*it);
            if (filePointer != nullptr) { //checks that file is in the system
                filePointer->accept(&asVisitor);
                fileSys->closeFile(filePointer);
                filePointer = 0;
            }
        }
        int numberTxtFiles = asVisitor.getNumTxts();
        int numberImgFiles = asVisitor.getNumImgs();
        int totalTextBytes = asVisitor.getTextBytes();
        int totalImgBytes = asVisitor.getImageBytes();

        cout << "Total number of files: " << numberTxtFiles + numberImgFiles << endl;
        cout << "Number of text files: " << numberTxtFiles << endl;
        cout << "Number of image files: " << numberImgFiles << endl;
        cout << "Total number of bytes required (1 byte/char, excluding filenames): " << totalImgBytes + totalTextBytes << endl;
        cout << "Number of text file bytes: " << totalTextBytes << endl;
        cout << "Number of image file bytes: " << totalImgBytes << endl;

        return returns::SUCCESS;
    }
    return returns::INVALID_COMMAND;
}
