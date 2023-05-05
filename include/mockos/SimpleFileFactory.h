#pragma once

/*
* Lab 5
* File: SimpleFileFactory.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class SimpleFileFactory, which inherits the interface from AbstractFileFactory.
*/

#include "AbstractFileFactory.h"
#include <string>
using namespace std;

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename) override;
};