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
#include "mockos/PasswordProxy.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/enums.h"

using namespace std;

AggregateStatsCommand::AggregateStatsCommand(AbstractFileSystem* afs) {
    fileSys = afs;
    numberTxtFiles = 0;
    numberImgFiles = 0;
    numberOpenFiles = 0;
    totalCommands = 0;
    totalSpace = 0;
}

void AggregateStatsCommand::displayInfo() { //usage information for ds
    cout << "as displays the file system's aggregate statistics, as can be invoked with the command : as" << endl;
}

int AggregateStatsCommand::execute(std::string command){
    set<string> files = fileSys->getFileNames();

    if (command.size() == 0) { //checks that command was passed in properly
        AggregateStatisticsVisitor asVisitor;
        for (set<string>::iterator it = files.begin(); it != files.end(); ++it) { //iterates through files
            istringstream iss(command);
            string filename;
            iss >> filename;
            AbstractFile* filePointer = fileSys->openFile(filename);
            filePointer->accept(&asVisitor);
            fileSys->closeFile(filePointer);
            filePointer = 0;
        }

        numberImgFiles = asVisitor.imgfiles;
        numberTxtFiles = asVisitor.txtfiles;


        cout << "Total number of files: " << numberTxtFiles + numberImgFiles << endl;
        cout << "Number of text files: " << numberTxtFiles << endl;
        cout << "Number of image files: " << numberImgFiles << endl;
        //cout << "Number of open files: " << numberOpenFiles << endl;
        cout << "Number of commands: " << totalCommands << endl;
        cout << "Storage used: " << totalSpace << endl;

        return returns::SUCCESS;
    }
    return returns::INVALID_COMMAND;
}