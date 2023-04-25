#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>

using namespace std;

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* fileSys;
	AbstractFileFactory* fileFact;
public: 
	TouchCommand(AbstractFileSystem* afs, AbstractFileFactory* aff);
	//virtual ~AbstractCommand();
	virtual void displayInfo() override;
	virtual int execute(std::string command) override;
};