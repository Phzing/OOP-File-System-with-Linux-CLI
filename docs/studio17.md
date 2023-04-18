# Studio 17
1. Zach Hoffman, Jillian Tarlowe, Geoffrey Lien

2. Tested functionality using the example input character vector provided. Result looked as expected:

X X
 X
X X

3. Programming this way using interface inheritance allows for easily extendable as well as consistent code.
This way, we can define how different types of files should be interacted with, but in a way that the function
names will always be the same since the interface is being inherited.

4. In order to be able to make object's of new concrete file types, we would need to add code to SimpleFileSystem.cpp's
createFile() function. Currently, this function will only create files of type imageFile and textFile.

5. Passes all of the unit tests!