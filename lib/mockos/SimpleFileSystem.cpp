/*
* Lab 5
* File: SimpleFileSystem.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions for the simple file system.
*/

#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "mockos/enums.h"

using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* af) { //adds a file into the map
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) {
		if (it->second == af) { //ensures that the file doesn't already exist
            cout << "File already exists" <<endl;
			return returns::FILE_ALREADY_EXISTS; 
		}
        else if (it->first == af->getName()){ //ensures that the file doesn't already exist
            cout << "File already exists" << endl;
            return returns::FILENAME_TAKEN; 
        }
	}
	if (af == nullptr) { //ensures the given pointer is not a nullptr
		return returns::NULL_PTR;
	}
	this->files.insert({ filename, af });
	return returns::SUCCESS;
}


AbstractFile* SimpleFileSystem::openFile(string filename) { //opens a given file
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) { //check that file exists
		if (it->first.compare(filename) == 0) {
			for (set<AbstractFile*>::iterator itr = this->openFiles.begin(); itr != this->openFiles.end(); ++itr) {
				if ((*itr)->getName().compare(filename) == 0) { //checks that file is not already open
					return nullptr;
				}
			}
			this->openFiles.insert(it->second);
			return it->second;
		}
	}
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* af) { //close an open file
	bool foundFile = false;
	for (set<AbstractFile*>::iterator itr = this->openFiles.begin(); itr != this->openFiles.end(); ++itr) {
		if (*itr == af) {
			openFiles.erase(af); //remove file from open list
			return returns::SUCCESS; 
		}
	}
	return returns::FILE_NOT_OPEN; //file was not open, so cannot be closed
}

int SimpleFileSystem::deleteFile(string filename) { //deletes a file from the system
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) { //checks that file exists
		if (it->first.compare(filename) == 0) {
            for (set<AbstractFile *>::iterator itr = this->openFiles.begin(); itr != this->openFiles.end(); ++itr) {
                if ((*itr)->getName().compare(filename) == 0) { //checks if file is open
                    return returns::FILE_OPEN; //File already open, couldn't be deleted
                }
            }
            delete it->second;
            files.erase(filename); //deletes the file from the map
            return returns::SUCCESS;
        }
	}
    cout << "File does not exist" << endl;
	return returns::FILE_DOES_NOT_EXIST; //cannot delete a file that does not exist
}

set<string> SimpleFileSystem::getFileNames() { 
	set<string> allFiles;
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) {
		allFiles.insert(it->first);
	}
	return allFiles;
}