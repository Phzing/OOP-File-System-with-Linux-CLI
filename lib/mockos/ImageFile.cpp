/*
* Lab 5
* File: ImageFile.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions for an image file.
*/

#include "mockos/ImageFile.h"
#include <string>
#include <iostream>
#include <vector>
#include "mockos/AbstractFileVisitor.h"
#include "mockos/enums.h"

using namespace std;

ImageFile::ImageFile(string n) {
	this->name = n;
	this->Size = 0;
}

unsigned int ImageFile::getSize() { //returns the size of the image file
	return contents.size();
}

unsigned int ImageFile::getDimension() { //returns the dimensions of the file
	return Size;
}

string ImageFile::getName() { //returns the name of the file
	return name;
}

int ImageFile::write(vector<char> v) { //uses user input to correctly store the image in a vector
	char futureSize = (int)v[v.size()-1] - 48; // fix hardcode
	char curr;
	vector<char> futureContents;
	for (int i = 0; i < (int)futureSize*(int)futureSize; i++) {
		curr = v[i];
		if (curr != 'X' && curr != ' ') {
			return returns::INVALID_IMAGE; //an image can only be 'X' or ' ' 
		}
		futureContents.push_back(curr);
	}
	Size = futureSize;
	contents = futureContents;
	return returns::SUCCESS;
}

int ImageFile::append(vector<char> v) {
	return returns::CANNOT_APPEND_IMAGES; // append is not supported by this file type
}

vector<char> ImageFile::read() { //returns the contents of the file, which iare displayed by the display visitor
	return this->contents;
}

void ImageFile::accept(AbstractFileVisitor* afv) { //accept method for the abstract file visitor
	afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string copyName) { //creates a copy of the image file
	copyName += ".img";
	AbstractFile* copy = new ImageFile(copyName);
	vector<char> toWrite = this->contents;
	toWrite.push_back(char(this->Size)+48);
	int writeReturn = copy->write(toWrite);
	//copy->write(this->contents);
	return copy;
	
}