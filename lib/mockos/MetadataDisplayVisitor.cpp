#include "mockos/MetadataDisplayVisitor.h"
#include <vector>
#include <iostream>

using namespace std;

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imgf) {
    cout << "file name: " << imgf->getName() << endl;
    cout << "size: " << imgf->getSize() << endl;
    cout << "type: image" << endl;
}

void MetadataDisplayVisitor::visit_TextFile(TextFile * tf) {
    cout << "file name: " << tf->getName() << endl;
    cout << "size: " << tf->getSize() << endl;
    cout << "type: text" << endl;
}