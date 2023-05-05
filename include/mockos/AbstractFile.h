#pragma once

/*
* Lab 5
* File: AbstractFile.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the AbstractFile interface.
*/

#include <vector>
#include <string>

class AbstractFileVisitor;
using namespace std;

class AbstractFile { //abstract file interface
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(string copyName) = 0;
};