#pragma once

/*
* Lab 5
* File: AbstractCommand.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the interface for AbstractCommand.
*/

#include <string>

class AbstractCommand { //interface for an abstract command
public:
    virtual int execute(std::string command) = 0;
    virtual void displayInfo() = 0;
    virtual ~AbstractCommand() = default;
};