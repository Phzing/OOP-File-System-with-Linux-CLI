#include "mockos/AbstractFile.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/AbstractFile.h"
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string filename) {
	string filetype;
	bool atDot = false;
	int dotPos = filename.find(".");
	dotPos++;
	filetype = filename.substr(dotPos);
	if (filetype.compare("txt") == 0) {
		TextFile* tf = new TextFile(filename);
		return tf; //success
	}
	else if (filetype.compare("img") == 0) {
		ImageFile* imgf = new ImageFile(filename);
		return imgf; //success
	}
	return nullptr; //Unrecognized filetype. No file created FIX HARDCODE
}