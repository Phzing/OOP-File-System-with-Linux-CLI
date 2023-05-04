#include "mockos/CatCommand.h"
#include "mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs) {
    fileSys = afs;
}

void CatCommand::displayInfo() {
    cout << "cat concatenates a file, cat can be invoked with the command : cat <filename> [-a]" << endl;
}

int CatCommand::execute(string command) {
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
        if (remString == "-a") {
            vector<char> contents = filePointer->read();
            for (int i = 0; i < contents.size(); i++) {
                cout << contents[i];
            }
            cout << endl;
        }
        else {
            cout << "Invalid usage of cat" << endl;
            return -2; // FIX HARDCODE
        }
    }
    cout << "Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exit without saving" << endl;
    string appendingData;
    string currentLine;
    getline(cin, currentLine);
    while (currentLine != ":wq" && currentLine != ":q") {
        appendingData = appendingData + currentLine + "\n";
        getline(cin, currentLine);
    }
    if (currentLine == ":q") {
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return 0; // success FIX HARDCODE
    }
    vector<char> appendingDataVec;
    string filetype;
    bool atDot = false;
    int dotPos = filename.find(".");
    dotPos++;
    filetype = filename.substr(dotPos);
    for (int i = 0; i < appendingData.size()-1; i++) {
        appendingDataVec.push_back(appendingData[i]);
    }
    if (remString == "-a") {
        int appendReturn = filePointer->append(appendingDataVec);
        fileSys->closeFile(filePointer);
        filePointer = 0;
        return appendReturn;
    }
    int writeReturn = filePointer->write(appendingDataVec);
    fileSys->closeFile(filePointer);
    filePointer = 0;
    return writeReturn;
}