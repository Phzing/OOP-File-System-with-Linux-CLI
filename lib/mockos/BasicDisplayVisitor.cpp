#include "mockos/BasicDisplayVisitor.h"
#include <vector>
#include <iostream>

using namespace std;

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imgf) {
	vector<char> contents = imgf->read();
	int size = imgf->getSize();
	for (int y = size - 1; y >= 0; y--) {
		for (int x = 0; x < size; x++) {
			cout << contents[y * size + x];
		}
		cout << endl;
	}
	cout << endl;
}

void BasicDisplayVisitor::visit_TextFile(TextFile * tf) {
	vector<char> contents = tf->read();
	for (int i = 0; i < contents.size(); i++) {
		cout << contents[i];
	}
	cout << endl;
}