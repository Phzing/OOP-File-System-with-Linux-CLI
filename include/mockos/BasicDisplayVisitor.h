#pragma once
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile*) override;
	virtual void visit_TextFile(TextFile*) override;
};