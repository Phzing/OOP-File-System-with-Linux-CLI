#pragma once
#include <vector>
#include <string>
#include "mockos/AbstractFileSystem.h"
#include <map>
#include <set>
using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* af) override;
	virtual int deleteFile(string filename) override;
	virtual AbstractFile* openFile(string filename) override;
	virtual int closeFile(AbstractFile* af) override;
	virtual set<string> getFileNames() override;
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
};