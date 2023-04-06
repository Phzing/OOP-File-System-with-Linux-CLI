using namespace std;

#include <vector>
#include "mockos/AbstractFile.h"
#include "mockos/TextFile.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	//cout << "hello world";
	
	//TextFile* myFile = new TextFile("aaa");
	AbstractFile* myFile = new TextFile("aaa");
	string h = "hello";
	vector<char> v;
	for (int i = 0; i < h.size(); i++) {
		v.push_back(h[i]);
		//cout << v[i];
	}
	myFile->write(v);
	myFile->read();
	return 0;
}

