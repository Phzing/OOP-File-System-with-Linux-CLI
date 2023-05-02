#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
#include <vector>

using namespace std;

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
public:
	DisplayCommand(AbstractFileSystem* afs);
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};