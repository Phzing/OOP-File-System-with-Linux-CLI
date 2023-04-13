#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
public:
	int addFile(string filename, AbstractFile* af);
	int createFile(string filename);
	int deleteFile(string filename);
	AbstractFile* openFile(string filename);
	int closeFile(AbstractFile* af);
};