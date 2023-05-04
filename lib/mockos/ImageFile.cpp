#include "mockos/ImageFile.h"
#include <string>
#include <iostream>
#include <vector>
#include "mockos/AbstractFileVisitor.h"
using namespace std;

ImageFile::ImageFile(string n) {
	this->name = n;
	this->Size = 0;
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

unsigned int ImageFile::getDimension() {
	return Size;
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> v) {
	char futureSize = (int)v[v.size()-1] - 48; // fix hardcode
	char curr;
	vector<char> futureContents;
	for (int i = 0; i < (int)futureSize*(int)futureSize; i++) {
		curr = v[i];
		if (curr != 'X' && curr != ' ') {
			return -1; //fix hardcode
		}
		futureContents.push_back(curr);
	}
	Size = futureSize;
	contents = futureContents;
	return 0; // success
}

int ImageFile::append(vector<char> v) {
	return -2; // FIX HARDCODE (functionality not supported by this file type)
}

vector<char> ImageFile::read() {
	return this->contents;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string copyName) {
	copyName += ".img";
	AbstractFile* copy = new ImageFile(copyName);
	vector<char> toWrite = this->contents;
	toWrite.push_back(char(this->Size)+48);
	int writeReturn = copy->write(toWrite);
	//copy->write(this->contents);
	return copy;
	
}