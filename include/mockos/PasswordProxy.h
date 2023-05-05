#pragma once

/*
* Lab 5
* File: PasswordProxy.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class PasswordProxy, which allows the user to create a file that is protected with a password.
*/

#include "mockos/AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile{
    AbstractFile * fileptr;
    string password;
protected:
    string passwordPrompt();
    bool checkPass(string input);
public:
    PasswordProxy(AbstractFile * fileptr, string password);
    ~PasswordProxy();
    virtual vector<char> read() override;
    virtual int write(vector<char>) override;
    virtual int append(vector<char>) override;
    virtual unsigned int getSize() override;
    virtual string getName() override;
    virtual void accept(AbstractFileVisitor*) override;
    virtual AbstractFile* clone(string copyName) override;
};