using namespace std;

#include <vector>
#include "mockos/AbstractFile.h"
#include "mockos/ImageFile.h"
#include "mockos/SimpleFileSystem.h"
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


	SimpleFileSystem sfh;
	sfh.addFile(myFile->getName(), myFile);
	string filename = "hello.img";
	int y = sfh.createFile(filename);
	AbstractFile* af = sfh.openFile("aaa");
	af->read();
	sfh.closeFile(af);
	int x = sfh.deleteFile("aaa");

	AbstractFile* af2 = sfh.openFile(filename);
	cout << "af2: " << af2 << endl;
	af2->write(v);
	af2->read();

	return 0;
}