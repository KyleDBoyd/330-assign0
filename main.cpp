#include <iostream>
#include "file.h"
#include "tax.h"

using namespace std;

int main()
{
	// Variables
	const char *filename = "tax.txt";
	string currentLine, taxName, taxIncome;

	// Initialize class objects
	File file(filename);
	Tax tax;

	// Open file
	file.openFile();

	// Process file
	while(!file.isEndOfFile()) {
		// Get next line
		currentLine = file.getLine();
		// Make sure line isn't empty
		if(!file.isEmptyLine(currentLine)) {
			// Make sure line length isn't over 80 characters
			if(file.isValidLineLength(currentLine)) {
				// Get tax name from current line
				taxName = tax.getName(currentLine);
				// Get tax income from current line
				taxIncome = tax.getIncome(currentLine);
				//cout << "Name:" << taxName << endl;
				//cout << "Income:" << taxIncome << endl;

			} else {
				// Inform user that the line length exceeds the limit
			}
		} else {
			// Inform user the line is empty
			cout << "empty line" << endl;
		}

	}

	// Close file
	file.closeFile();

	return 0;
}
