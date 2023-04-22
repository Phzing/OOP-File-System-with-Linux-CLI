#include <iostream>
#include <string>
#include <vector>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "here" << endl;
	AbstractFile* myFile = new ImageFile("aaa");
	AbstractFile* myFile2 = new TextFile("bbb");
	vector<char> contents = myFile->read();
	/*
	cout << "Contents (initial read):";
	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout << endl;
	*/
	for (int i = 0; i < 5; ++i) {
		contents.push_back('X');
		contents.push_back(' ');
	}
	contents.push_back('3');
	myFile->write(contents);
	myFile2->write(contents);
	//cout << "in loop" << endl;
	//contents = myFile->read();
	/*
	cout << "Contents (second read):";
	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout << endl;
	*/
	MetadataDisplayVisitor MetadataDisplayVisitor;
	myFile->accept(&MetadataDisplayVisitor);
	//myFile2->accept(&displayVisitor);

	return 0;

}