#include <iostream>
#include <string>
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"

using namespace std;


int main(int argc, char* argv[]) {
	
	AbstractFileSystem* system = new SimpleFileSystem; //maybe 
	AbstractFileFactory* factory = new SimpleFileFactory;
	AbstractFile* temp = factory->createFile("hello.txt");
	AbstractFile* temp2 = factory->createFile("hello.img");
	system->addFile("hello.txt", temp);
	system->openFile("hello.txt");
	system->closeFile(temp);
	system->deleteFile("hello.txt");
	system->addFile("hello.img", temp2);
	system->openFile("hello.img");
	system->closeFile(temp2);
	system->deleteFile("hello.img");
	return 0;

}