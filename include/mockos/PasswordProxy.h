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
    virtual vector<char> read() override;
    virtual int write(vector<char>) override;
    virtual int append(vector<char>) override;
    virtual unsigned int getSize() override;
    virtual string getName() override;
    virtual void accept(AbstractFileVisitor*) override;

};