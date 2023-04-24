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
    vector<char> contents = myFile->read();
    for (int i = 0; i < 5; ++i) {
        contents.push_back('X');
        contents.push_back(' ');
    }
    contents.push_back('3');
    myFile->write(contents);
    PasswordProxy *proxy = new PasswordProxy(myFile, "password");
    contents = proxy->read();
    cout << "Contents:";
    for (int i = 0; i < contents.size(); i++) {
        cout << contents[i];
    }
    cout << endl;
    

    MetadataDisplayVisitor MetadataDisplayVisitor;
    proxy->accept(&MetadataDisplayVisitor);


    return 0;
}