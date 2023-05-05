/*
* Lab 5
* File: AggregateStatisticsVisitor.cpp
* Authors:
* Geoffrey Lien g.lien@wustl.edu
* Zach Hoffman hoffman.z@wustl.edu
* Jillian Tarlowe jilliantarlowe@wustl.edu
* Purpose: This file defines all functions used by an aggregate statistics visitor.
*/

#include "mockos/AggregateStatisticsVisitor.h"
#include "mockos/SimpleFileSystem.h"
#include <vector>
#include <iostream>
#include "mockos/enums.h"

using namespace std;

void AggregateStatisticsVisitor::visit_ImageFile(ImageFile* imgf){
	imgfiles++;
}

void AggregateStatisticsVisitor::visit_TextFile(TextFile* tf){
	txtfiles++;
}

