# Studio 16

1. Zach Hoffman, Jillian Tarlowe, Geoffrey Lien

2a. In C++, an interface is the functionality that a class provides for the client code to interact with the class,
including functions and all non-private members. To have an abstract class (or an interface that we want to be inherited),
all functions that we want to be inherited and later overwritten should be declared as virtual in the base class, and once 
again virtual in all of the subsequent inherited classes. Also, "override" should be added every time the function is 
overwritten in the inherited classes.

3. 
a. This is interface inheritance, since no implimentation was inherited.
b. Private, since we only want to access those variables within the text file class.  COME BACK

4. To test, we made an object and passed it a vector<char> populated with "hello" using write(). Then, we tried read(), and 
saw "hello" printed out to us.

5. To do this, we swtitched the type of the TextFile from type TextFile to type AbstractFile and then tried the same thing.

6. Test file passed


