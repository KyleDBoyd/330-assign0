#ifndef FILE_H
#define FILE_H

// Library includes
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>

using namespace std;

class File {

    // Class constants
    const int lineCharacterLimit = 80;

    // Class variables
    ifstream infile;
    const char *filename;
    string currentLine;
    int lineNumber = 0;

    public:

        // Constructor
        File(char *c);
        // Destructor
        ~File();
        // Opens file. Throw error if it fails to open.
        void openFile();
        // Close file. Throw error if it fails to close.
        void closeFile();
        // Checks to see if we have reached the end of the file.
        bool isEndOfFile();
        // Get next line from file
        string getLine();
        // Check file input line length to ensure it is not over 80 characters.
        bool isValidLineLength(string s);
        // Check if line is empty
        bool isEmptyLine(string s);
        // Get line number of current file stream
        int getLineNumber();

};

#endif
