#pragma once
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <string>

class AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile*) = 0;
	virtual void visit_TextFile(TextFile*) = 0;
};