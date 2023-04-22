#pragma once
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


};