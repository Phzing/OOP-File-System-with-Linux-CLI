#pragma once

/*
* Lab 5
* File: SimpleFileSystem.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the SimpleFileSystem class inherited from the AbstractFileSystem interface 
* and declares all related functions and member variables.
*/

#include <vector>
#include <string>
#include "mockos/AbstractFileSystem.h"
#include <map>
#include <set>
using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* af) override;
	virtual int deleteFile(string filename) override;
	virtual AbstractFile* openFile(string filename) override;
	virtual int closeFile(AbstractFile* af) override;
	virtual set<string> getFileNames() override;
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
};