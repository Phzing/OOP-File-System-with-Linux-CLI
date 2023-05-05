/*
* Lab 5
* File: MetadataDisplayVisitor.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used by a MetadataDisplayVisitor.
*/

#include "mockos/MetadataDisplayVisitor.h"
#include <vector>
#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imgf) { //displays an image file's metadata
    cout << "file name: " << imgf->getName() << endl;
    cout << "size: " << imgf->getSize() << endl;
    cout << "type: image" << endl;
}

void MetadataDisplayVisitor::visit_TextFile(TextFile * tf) { //displays a text file's metadata
    cout << "file name: " << tf->getName() << endl;
    cout << "size: " << tf->getSize() << endl;
    cout << "type: text" << endl;
}