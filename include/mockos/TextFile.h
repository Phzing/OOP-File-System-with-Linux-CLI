#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class TextFile : public AbstractFile {
public:
	TextFile(string n);
	virtual void read() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual unsigned int getSize() override;
	virtual string getName() override;
private:
	vector<char> contents;
	string name;
};