# Studio 21
1. Zach Hoffman, Geoffrey Lien, Jillian Tarlowe

2. It is important to declare a virtual destructor so we can indicate that the AbstractCommand destructor must be 
overridden in any derived classes.

3. Since the command prompt doesn't need to know what the concrete types of the objects it uses,
this allows the command prompt to be very flexible as it can use all different types of objects that
the user can define for whatever purpose suits their needs the best. Since all of the member variables
use pointers to base classes, the command prompt can be easily configured to use any file system that 
is desired (as well as its associated factory).

4. Tried calling 'help', 'help touch', 'touch hello.txt', 'q' and then checking if hello.txt was opened
successfully from the file system. All worked correctly.

5.Test cases pass.