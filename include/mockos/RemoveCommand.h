#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

using namespace std;

class RemoveCommand : public AbstractCommand {
    AbstractFileSystem* fileSys;
public:
    RemoveCommand(AbstractFileSystem* afs);
    //virtual ~AbstractCommand();
    virtual void displayInfo() override;
    virtual int execute(std::string filename) override;
};