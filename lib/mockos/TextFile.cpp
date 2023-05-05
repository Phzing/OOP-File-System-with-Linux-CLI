/*
* Lab 5
* File: TextFile.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines functions for a text file.
*/

#include "mockos/TextFile.h"
#include <string>
#include <iostream>
#include <vector>
#include "mockos/AbstractFileVisitor.h"
#include "mockos/enums.h"

using namespace std;

TextFile::TextFile(string n) {
	this->name = n;
}

unsigned int TextFile::getSize() { //returns the size of the file
	return contents.size();
}

string TextFile::getName() { //returns the file name
	return name;
}

int TextFile::write(vector<char> v) { //overwrites the contents of the file
	contents = v;
	return returns::SUCCESS; 
}

int TextFile::append(vector<char> v) { //adds new information to the end of the file
	for (int i = 0; i < v.size(); i++) {
		contents.push_back(v[i]);
	}
	return returns::SUCCESS; 
}

vector<char> TextFile::read() { //returns the contents of the file, which are displayed by the display visitor
	return contents;
}

void TextFile::accept(AbstractFileVisitor* afv) { //accept method for the abstract file visitor
	afv->visit_TextFile(this);
}


AbstractFile* TextFile::clone(string copyName) { //creates a copy of the text file
	copyName += ".txt";
	AbstractFile* copy = new TextFile(copyName);
	copy->write(this->contents);
	return copy;
}