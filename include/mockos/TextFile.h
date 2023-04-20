#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
using namespace std;

class TextFile : public AbstractFile {
public:
	TextFile(string n);
	virtual vector<char> read() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
private:
	vector<char> contents;
	string name;
};