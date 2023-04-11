using namespace std;

#include <vector>
#include "mockos/AbstractFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	//cout << "hello" << endl;
	AbstractFile* myFile = new ImageFile("aaa");
	string h = "X X X X X3";
	vector<char> v;
	for (int i = 0; i < h.size(); i++) {
		v.push_back(h[i]);
		//cout << v[i];
	}
	myFile->write(v);
	myFile->read();
	return 0;
}