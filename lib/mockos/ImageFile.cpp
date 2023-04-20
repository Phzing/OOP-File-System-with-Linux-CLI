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
	//return contents.size();
	return Size;
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> v) {
	Size = (int)v[v.size()-1] - 48; // fix hardcode
	char curr;
	for (int i = 0; i < (int)Size*(int)Size; i++) {
		curr = v[i];
		if (curr != 'X' && curr != ' ') {
			vector<char> zeroed;
			contents = zeroed;
			Size = 0;
			return -1; //fix hardcode
		}
		contents.push_back(curr);
	}
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
