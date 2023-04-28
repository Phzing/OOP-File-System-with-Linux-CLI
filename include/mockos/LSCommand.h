#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
#include <set>
using namespace std;

class LSCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	LSCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};