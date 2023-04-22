# Studio 19
1. Zach Hoffman, Jillian Tarlowe, Geoffrey Lien

2. Created a TextFile and ImageFile, read its contents vector, printed it out, changed its contents vector and 
rewrote contents to the File, then read it again. Printed contents vector with cout after each read. Saw contents
vector populated after second read.

3. The visitor interface defines a set of visit methods to a specific type of the element. The element must also
define an accept method to take the visitor as a parameter. The visitor then calls on the object to utilize the object's
properties to perform a function, in our case reading the file.

4. Delegating the read functionality of a file to BasicDisplayVisitor is crucial to preventing cluttering of the file
interface. Rather than implementing read directly into the file class, we create a visitor interface that has the 
purpose of visiting the file to then output its contents into the console. This allows us to keep the creation and
properties of the file separate from the read/output functionality.

5. The problem with using a visitor pattern and then creating a new concrete file type class 
is that we would need to implement all the new visitor methods for the new file type and therefore modify
each visitor class.