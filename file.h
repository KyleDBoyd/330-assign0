#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class File {

    ifstream infile;
    const char *filename;
    string currentLine;

    public:

        // Constructor
        File(const char *c);
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

};

#endif
