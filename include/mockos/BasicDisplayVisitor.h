#pragma once

/*
* Lab 5
* File: BasicDisplayVisitor.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the BasicDisplayVisitor class, which inherits the interface from AbstractFileVisitor.
* Its purpose is to go to a given file and display its contents.
*/

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor { 
public:
	virtual void visit_ImageFile(ImageFile*) override;
	virtual void visit_TextFile(TextFile*) override;
};