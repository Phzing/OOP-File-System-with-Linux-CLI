# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name: Geoffrey Lien, Zach Hoffman, Jillian Tarlowe
Lab #: 5

Document your lab work here according to the lab specification

In order to test everything, each time functionality was added, we implemented it in main and 
tested it in every way we could think of. For example, when TouchCommand was implemented, we
tested it by adding .txt and .img files, both with and without a password. Similar tests were
run every time new commands were added, testing them in all the significantly different ways we
could think of (i.e. always testing with all file types for both password protected and not, and 
with and without the optional endings [-a], [-d], [-p], etc.).

During the process of the lab, there were many bugs and errors we ran into, so many so that it's 
hard to remember them all. Some of the biggest ones we remember were:
-Many times had problems being able to correctly construct objects
-Had a bug in ImageFile's implementation of write() where it was trying to immediately write to the
file before it finished checking for valid input, and was also appending rather than writing.
-Had a lot of trouble  implementing the prototype pattern for CopyCommand initially because had a 
slight misunderstanding about what the pattern meant (thought we needed to use *this to initialize)
-Accidentally had a pure virtual MacroCommand implementation initially
-Problem with double '&' in command prompt after creating a password protected file (fixed)
-Forgetting to close files at the end of functions, resulting in not being able to open/access 
them in the future. 
-In the extra credit, we accidentally called getSize() instead of getDimension(), but on the first trial
realized this was incorrect and fixed it.

For the extra credit, we got permission to implement and implemented a command and visitor pair that
aggregates statistics about the files in the system. The statistics its aggregates are the total number
of text files and image files, and the total number of bytes stored in all of the files (excluding the 
filenames). To test these, we tried adding files with touch/touchcat and calling 'as' and looked at the 
output, which all looked good. 

Division of work:
For studios, we all came to class to work together during the scheduled class times and 
collaborated to find solutions to all of the steps. On the lab, a similar approach was taken.
Though we had a little more asynchronous work with the lab, we often ended up texting, calling, or
getting on Zoom with each other to brainstorm solutions to problems and implement further steps.
Overall, we were all happy with the division of work.