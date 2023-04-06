#pragma once
#include <vector>
#include <string>
using namespace std;

class AbstractFile {
public:
	virtual void read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
};