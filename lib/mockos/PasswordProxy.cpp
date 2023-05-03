#include "mockos/PasswordProxy.h"
#include <iostream>

using namespace std;

string PasswordProxy:: passwordPrompt() {
        cout << "Please input a password to access the file:" << endl;
        string input;
        cin >> input;
        return input;
}

bool PasswordProxy:: checkPass(string input) {
        if (input.compare(this->password) == 0){
            return true;
        }
        return false;
    }

PasswordProxy::PasswordProxy(AbstractFile *fileptr, string password) {
    this->fileptr = fileptr;
    this->password = password;
}

PasswordProxy:: ~PasswordProxy(){
    delete fileptr;
}

vector<char> PasswordProxy:: read(){
    string input = passwordPrompt();
    //cout << "Password gotten: " << input << endl;
    if (this->checkPass(input) == true){
        //cout << "passwords match!" << endl;
        return this->fileptr->read();
    }
    vector<char> empty;
    return empty;
}

int PasswordProxy::write(vector<char> v){
    string input = passwordPrompt();
    if (this->checkPass(input) == true) {
        cout << "wrote password" << endl;
        return this->fileptr->write(v);
    }
    return -1; //fix hardcode new int needed instead of -1
}

int PasswordProxy::append(vector<char> v){
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        return this->fileptr->append(v);
    }
    return -1; //fix hardcode new int needed instead of -1
}

unsigned int PasswordProxy::getSize(){
    return this->fileptr->getSize();
}

string PasswordProxy::getName(){
    return this->fileptr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv){
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        return this->fileptr->accept(afv);
    }
}

AbstractFile* PasswordProxy::clone(string copyName) {
    AbstractFile* filePointer = this->fileptr->clone(copyName);
    AbstractFile* copy = new PasswordProxy(filePointer, this->password);
    return copy;
}
