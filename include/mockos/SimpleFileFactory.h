#pragma once
#include "AbstractFileFactory.h"
#include <string>
using namespace std;

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename) override;
};