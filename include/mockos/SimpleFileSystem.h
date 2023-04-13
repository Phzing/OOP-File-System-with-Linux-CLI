#pragma once
#include <vector>
#include <string>
#include "mockos/AbstractFileSystem.h"
#include <map>
#include <set>
using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* af);
	virtual int createFile(string filename);
	virtual int deleteFile(string filename);
	virtual AbstractFile* openFile(string filename);
	virtual int closeFile(AbstractFile* af);
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
};