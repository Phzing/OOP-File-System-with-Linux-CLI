#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class ImageFile : public AbstractFile {
public:
	ImageFile(string n);
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual void read() override;
private:
	string name;
	vector<char> contents;
	char Size;
};