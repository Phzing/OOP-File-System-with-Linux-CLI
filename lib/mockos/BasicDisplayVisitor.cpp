/*
* Lab 5
* File: BasicDisplayVisitor.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used by a basic display visitor.
*/

#include "mockos/BasicDisplayVisitor.h"
#include <vector>
#include <iostream>
#include "mockos/enums.h"

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imgf) { //displays the contents of an image file
	vector<char> contents = imgf->read();
	int size = imgf->getDimension();
	for (int y = size - 1; y >= 0; y--) {
		for (int x = 0; x < size; x++) {
			cout << contents[y * size + x];
		}
		cout << endl;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_TextFile(TextFile * tf) { //displays the countents of a text file
	vector<char> contents = tf->read();
	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout << endl;
}