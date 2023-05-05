/*
* Lab 5
* File: PasswordProxy.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used in PasswordProxy.
*/

#include "mockos/PasswordProxy.h"
#include <iostream>
#include "mockos/enums.h"

using namespace std;

string PasswordProxy:: passwordPrompt() { //prompts the user to input a password and returns it
        cout << "Please input a password to access the file:" << endl;
        string input;
        cin >> input;
        return input;
}

bool PasswordProxy:: checkPass(string input) { //checks if an inputed password matches the saved password
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

vector<char> PasswordProxy:: read(){ //displays a file if the correct password is given
    string input = passwordPrompt();
    //cout << "Password gotten: " << input << endl;
    if (this->checkPass(input) == true){
        //cout << "passwords match!" << endl;
        return this->fileptr->read();
    }
    vector<char> empty;
    return empty;
}

int PasswordProxy::write(vector<char> v){ //calls write() on a file if the given password is correct
    string input = passwordPrompt();
    if (this->checkPass(input) == true) {
        cout << "wrote password" << endl;
        return this->fileptr->write(v);
    }
    return returns::INCORRECT_PASSWORD;
}

int PasswordProxy::append(vector<char> v){ //calls append() on a file if the given password is correct
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        return this->fileptr->append(v);
    }
    return returns::INCORRECT_PASSWORD;
}

unsigned int PasswordProxy::getSize(){ //returns the size of the member variable pointer
    return this->fileptr->getSize();
}

string PasswordProxy::getName(){ //returns the name of the member variable pointer
    return this->fileptr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv){ //accept method for abstract file visitor
    string input = passwordPrompt();
    if (this->checkPass(input) == true){
        return this->fileptr->accept(afv);
    }
}

AbstractFile* PasswordProxy::clone(string copyName) { //creates a clone of a password protected file
    AbstractFile* filePointer = this->fileptr->clone(copyName);
    AbstractFile* copy = new PasswordProxy(filePointer, this->password);
    return copy;
}
