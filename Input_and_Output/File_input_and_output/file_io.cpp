/*
File Input and Output
---------------------

app     Opens the file in append mode
ate	    Seeks to the end of the file before reading/writing
binary	Opens the file in binary mode (instead of text mode)
in	    Opens the file in read mode (default for ifstream)
out	    Opens the file in write mode (default for ofstream)
trunc	Erases the file if it already exists


*/

#include <fstream>
#include <iostream>

//File Output
void file_output() {
    // ofstream is used for writing files
    // We'll make a file called Sample.txt
    // This will override the file.
    std::ofstream outf{ "Sample.txt" };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
    }

    // We'll write two lines into this file
    outf << "This is line 1\n";
    outf << "This is line 2\n";
    outf.close();

    // Oops, we forgot something
    outf.open("Sample.txt", std::ios::app);
    outf << "This is line 3\n";

    // When outf goes out of scope, the ofstream
    // destructor will close the file also.
}

#include<string>
//File Input
void file_input() {
    // ifstream is used for reading files
    // We'll read from a file called Sample.txt
    std::ifstream inf{ "Sample.txt" };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for reading!\n";
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        std::getline(inf, strInput);
        /*
        We could have used:

        inf >> strInput;

        However this would have broken on whitespace.
        This is not always what we want.
        */
        std::cout << strInput << '\n';
    }

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}

//Buffering
/*
We do not always have to write to disk immediately.
We can write to a buffer before writing to the disk.

If we close the file it will automatically flush the
buffer.

However, this is not always the case.
To do it manually you could use:

ostream::flush() function or sending 
std::flush to the output stream.
std::endl; also flushes the output stream
*/

//Appedning to a file

void appending_file() {

    // We'll pass the ios:app flag to tell the ofstream to append
    // rather than rewrite the file. We do not need to pass in std::ios::out
    // because ofstream defaults to std::ios::out
    std::ofstream outf{ "Sample.txt", std::ios::app };

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
    }

    outf << "This is line 3\n";
    outf << "This is line 4\n";

    // When outf goes out of scope, the ofstream
    // destructor will close the file
}