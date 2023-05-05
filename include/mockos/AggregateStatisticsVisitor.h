#pragma once

/*
* Lab 5
* File: AggregateStatisticsVisitor.h
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file declares the AggregateStatisticsVisitor class, which inherits the interface from AbstractFileVisitor.
* Its purpose is to gather statistics on our file system.
*/

#include "AbstractFileVisitor.h"
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

class AggregateStatisticsVisitor : public AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile*) override;
	virtual void visit_TextFile(TextFile*) override;
	int imgfiles = 0;
	int txtfiles = 0;
};