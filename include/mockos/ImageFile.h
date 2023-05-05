#pragma once

/*
* Lab 5
* File: ImageFile.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the ImageFile class and its related functions and member variables.
*/

#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class ImageFile : public AbstractFile {
public:
	ImageFile(string n);
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	unsigned int getDimension();
	virtual AbstractFile* clone(string copyName) override;
private:
	string name;
	vector<char> contents;
	char Size;
};