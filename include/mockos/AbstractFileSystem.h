#pragma once

/*
* Lab 5
* File: AbstractFileSystem.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the interface for file systems.
*/

#include <vector>
#include <string>
#include "AbstractFile.h"
#include <set>
using namespace std;

class AbstractFileSystem { //interface for file systems
public:
	virtual int addFile(string filename, AbstractFile* af) = 0;
	virtual int deleteFile(string filename) = 0;
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile* af) = 0;
	virtual set<string> getFileNames() = 0;
};