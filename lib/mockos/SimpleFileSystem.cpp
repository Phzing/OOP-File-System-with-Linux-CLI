#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* af) {
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) {
		if (it->second == af) {
			return -2; // file already exists FIX HARDCODE
		}
	}
	if (af == nullptr) {
		return -3; // file is a nullptr FIX HARDCODE
	}
	this->files.insert({ filename, af });
	return 0; //success
}

int SimpleFileSystem::createFile(string filename) {
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) {
		if (it->first.compare(filename) == 0) {
			return -4; // filename already in use FIX HARDCODE
		}
	}
	string filetype;
	bool atDot = false;
	int dotPos = filename.find(".");
	dotPos++;
	filetype = filename.substr(dotPos);
	if (filetype.compare("txt") == 0) {
		TextFile tf(filename);
		addFile(filename, &tf);
		return 0; //success
	}
	else if (filetype.compare("img") == 0) {
		ImageFile tf(filename);
		addFile(filename, &tf);
		return 0; //success
	}
	return -5; //File not created FIX HARDCODE
}

AbstractFile* SimpleFileSystem::openFile(string filename) {
	for (map<string, AbstractFile*>::iterator it = this->files.begin(); it != this->files.end(); ++it) {
		if (it->first.compare(filename) == 0) {
			for (set<AbstractFile*>::iterator itr = this->openFiles.begin(); itr != this->openFiles.end(); ++itr) {
				if ((*itr)->getName().compare(filename) == 0) {
					return nullptr;
				}
			}
			this->openFiles.insert(it->second);
			return it->second;
		}
	}
	return nullptr;
}
