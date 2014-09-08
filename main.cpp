#include <iostream>
#include <fstream>
#include <string>
#include "file.h"

using namespace std;

int main()
{
	// Variables
	const char *filename = "tax.txt";
	string currentLine;

	// Initialize file object
	File file(filename);

	// Open file
	file.openFile();

	// Process file
	while(!file.isEndOfFile()) {
		// Get next line
		currentLine = file.getLine();
		// Make sure line length isn't over 80 characters
		if(file.isValidLineLength()) {
			
		} else {
			// Inform user that the line length exceeds the limit
		}
	}

	// Close file
	file.closeFile();

	return 0;
}
