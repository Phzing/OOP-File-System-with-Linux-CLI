#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class CatCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	CatCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};