#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* af) = 0;
	virtual int deleteFile(string filename) = 0;
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile* af) = 0;
};