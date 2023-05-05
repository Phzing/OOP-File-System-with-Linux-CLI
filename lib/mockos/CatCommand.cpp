/*
* Lab 5
* File: CatCommand.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used by CatCommand.
*/

#include "mockos/CatCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/enums.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void CatCommand::displayInfo() { //usage information for cat
    cout << "cat concatenates a file, cat can be invoked with the command : cat <filename> [-a]" << endl;
}

int CatCommand::execute(string command) { //defines how cat is executed
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
        return returns::FILE_DOES_NOT_EXIST; // No file found in system
    }

    if (space) {
        iss >> remString;
        if (remString == "-a") { //checks that -a is present, meaning append was invoked
            vector<char> contents = filePointer->read();
            for (int i = 0; i < contents.size(); i++) {
                cout << contents[i];
            }
            cout << endl;
        }
        else { 
            cout << "Invalid usage of cat" << endl;
            return returns::INVALID_CAT_USE;
        }
    }

    cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
    string appendingData;
    string currentLine;
    getline(cin, currentLine);

    while (currentLine != ":wq" && currentLine != ":q") { //append functionality
        appendingData = appendingData + currentLine + "\n";
        getline(cin, currentLine);
    }

    if (currentLine == ":q") { //quit without saving changes
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return returns::SUCCESS;
    }

    vector<char> appendingDataVec;
    string filetype;
    bool atDot = false;
    int dotPos = filename.find(".");
    dotPos++;
    filetype = filename.substr(dotPos);

    for (int i = 0; i < appendingData.size()-1; i++) { //appends the given data
        appendingDataVec.push_back(appendingData[i]);
    }

    if (remString == "-a") {
        int appendReturn = filePointer->append(appendingDataVec);
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return appendReturn;
    }

    int writeReturn = filePointer->write(appendingDataVec);
    fileSys->closeFile(filePointer); //closes the file once the command has finished
    filePointer = 0;
    return writeReturn;
}