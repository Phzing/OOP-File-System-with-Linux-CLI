#pragma once

/*
* Lab 5
* File: AbstractFileVisitor.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the interface for an AbstractFileVisitor.
*/

#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <string>

class AbstractFileVisitor { //interface for an abstract file visitor
public:
	virtual void visit_ImageFile(ImageFile*) = 0;
	virtual void visit_TextFile(TextFile*) = 0;
};