# Studio 20
1. Zach Hoffman, Geoffrey Lien, Jillian Tarlowe

2. It is important that we delete the pointer to the actual file because if we don't delete the pointer, we will 
have a memory leak upon destruction of the PasswordProxy object.

3. Implemented all

4. Tested reading, writing, and displaying a file via the proxy object. First, had proxy object with no contents. Read and printed
out results from read. Nothing was printed. Then, wrote a vector into the file and returned the result of the write call (was a 0).
Read proxy again and printed results which showed the correct vector being printed. Then, created a MetadataDisplayVisitor object and 
called accept on our proxy, passing the MetadataDisplayVisitor object and saw the contents printed to the terminal ostream.

5. All unit tests pass