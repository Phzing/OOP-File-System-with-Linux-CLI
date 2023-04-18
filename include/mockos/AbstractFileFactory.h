#pragma once
#include "AbstractFile.h"
using namespace std;

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename) = 0;
};