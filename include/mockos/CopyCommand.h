#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

using namespace std;

class CopyCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	CopyCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};