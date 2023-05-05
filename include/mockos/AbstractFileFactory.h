#pragma once

/*
* Lab 5
* File: AbstractFileFactory.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the interface for an AbstractFileFactory.
*/

#include "AbstractFile.h"
using namespace std;

class AbstractFileFactory { //interface for an abstract file factory
public:
	virtual AbstractFile* createFile(string filename) = 0;
};