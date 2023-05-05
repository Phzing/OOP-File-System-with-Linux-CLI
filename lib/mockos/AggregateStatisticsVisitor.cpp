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

void AggregateStatisticsVisitor::visit_ImageFile(ImageFile* imgf) {
	imgFileCount++;
	int dimension = imgf->getDimension();
	totalImageBytes += dimension * dimension + 1;
}

void AggregateStatisticsVisitor::visit_TextFile(TextFile* tf) {
	txtFileCount++;
	vector<char> contents = tf->read();
	totalTextBytes += contents.size();
}

int AggregateStatisticsVisitor::getNumImgs() {
	return imgFileCount;
}

int AggregateStatisticsVisitor::getNumTxts() {
	return txtFileCount;
}

int AggregateStatisticsVisitor::getImageBytes() {
	return totalImageBytes;
}

int AggregateStatisticsVisitor::getTextBytes() {
	return totalTextBytes;
}