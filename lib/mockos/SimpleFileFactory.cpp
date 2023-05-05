/*
* Lab 5
* File: SimpleFileFactory.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in a simple file factory.
*/

#include "mockos/AbstractFile.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
#include "mockos/enums.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(string filename) { //creates a file
	string filetype;
	bool atDot = false;
	int dotPos = filename.find(".");
	dotPos++;
	filetype = filename.substr(dotPos);
	if (filetype.compare("txt") == 0) { //creates a text file if we find .txt
		TextFile* tf = new TextFile(filename);
		return tf; //success
	}
	else if (filetype.compare("img") == 0) { //creates an image file if we find .img
		ImageFile* imgf = new ImageFile(filename);
		return imgf; //success
	}
	return nullptr; //Unrecognized filetype, no file created
}