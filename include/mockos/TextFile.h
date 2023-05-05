#pragma once

/*
* Lab 5
* File: TextFile.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the TextFile class and its related functions and member variables.
*/

#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class TextFile : public AbstractFile {
public:
	TextFile(string n);
	virtual vector<char> read() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(string copyName) override;
private:
	vector<char> contents;
	string name;
};