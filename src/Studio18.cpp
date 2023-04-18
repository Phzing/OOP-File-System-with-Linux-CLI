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
	cout << "temp: " << temp << endl;
	system->addFile("hello.txt", temp);
	return 0;

}