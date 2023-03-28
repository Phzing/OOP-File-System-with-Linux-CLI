#pragma once;
#include <vector>
#include <string>
using namespace std;

class AbstractFile {
public:
	AbstractFile();
	virtual void read();
	virtual int write(vector<char>);
	virtual int append(vector<char>);
	virtual unsigned int getSize();
	virtual string getName();
};