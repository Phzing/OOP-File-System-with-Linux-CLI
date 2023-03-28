#include "mockos/TextFile.h"
#include <string>
#include <iostream>
using namespace std;

TextFile::TextFile(string n) {
	name = n;
}

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> v) {
	contents = v;
	return 0; // success
}

int TextFile::append(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		contents.push_back(v[i]);
	}
	return 0; // success
}

void TextFile::read() {
	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout << endl;
}

