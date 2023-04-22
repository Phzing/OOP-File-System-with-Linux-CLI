#pragma once
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


