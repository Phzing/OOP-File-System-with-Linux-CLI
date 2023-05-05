#pragma once

/*
* Lab 5
* File: MetadataDisplayVisitor.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the class MetaDataDisplayVisitor, which inherits the interface from AbstractFileVisitor.
* Its purpose is to display metadata about a given file, specifically its name, size, and type.
*/

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class MetadataDisplayVisitor : public AbstractFileVisitor { 
public:
    virtual void visit_ImageFile(ImageFile*) override;
    virtual void visit_TextFile(TextFile*) override;
};