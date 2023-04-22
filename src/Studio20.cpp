#include <iostream>
#include <string>
#include <vector>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "here" << endl;
    AbstractFile *myFile = new ImageFile("aaa");
    //the password for this file will be "password"
    PasswordProxy *proxy = new PasswordProxy(myFile, "password");
    vector<char> contents = proxy->read();

    for (int i = 0; i < 5; ++i) {
        contents.push_back('X');
        contents.push_back(' ');
    }
    contents.push_back('3');
    proxy->write(contents);

    MetadataDisplayVisitor MetadataDisplayVisitor;
    proxy->accept(&MetadataDisplayVisitor);


    return 0;
}