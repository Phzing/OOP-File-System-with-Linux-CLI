# Studio 16

1. Zach Hoffman, Jillian Tarlowe, Geoffrey Lien

2a. In C++, an interface is the functionality that a class provides for the client code to interact with the class,
including functions and all non-private members. To have an abstract class (or an interface that we want to be inherited),
all functions that we want to be inherited and later overwritten should be declared as pure virtual in the base class, and once 
again virtual in all of the subsequent inherited classes. Also, "override" should be added every time the function is 
overwritten in the inherited classes. Functions should be defined and implemented in the inherited classes.

3. 
a. This is interface inheritance. AbstractFile is our interface and functions are pure virtual, which means
no implimentation was inherited.
b. These member variables should be private. We only want to access those variables within the text file class. We do not want other
classes to be able to directly access the member variables.

4. To test, we made an object and passed it a vector<char> populated with "hello" using write(). Then, we tried read(), and 
saw "hello" printed out to us, meaning our test passed.

5. To do this, we swtitched the type of the TextFile from type TextFile to type AbstractFile and then tried the same thing.
	From this:
	TextFile* myFile = new TextFile("aaa");
	To this:
	AbstractFile* myFile = new TextFile("aaa");

6. Test file passed!


