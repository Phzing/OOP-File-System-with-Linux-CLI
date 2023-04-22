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
    if (this->checkPass(input) == true){
        //todo: return read value
    }
    vector<char> empty;
    return empty;
}

int PasswordProxy::write(vector<char> v){
    string input = passwordPrompt();
    if (this->checkPass(input) == true) {
        //todo: return write value
    }
    return -1; //fix hardcode
}

int PasswordProxy::append(vector<char> v){
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        //todo: return append value
    }
    return -1; //fix hardcode
}

unsigned int PasswordProxy::getSize(){
    return this->getSize();
}

string PasswordProxy::getName(){
    return this->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv){
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        //todo: return accept value
    }
}


