// Library includes
#include <iostream>
#include <stdlib.h>

// Class includes
#include "file.h"
#include "tax.h"
#include "cmd.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Initialize cmd object with command line arguments
	Cmd cmd(argc, argv);

	// Variables
	const char *filename = "tax.txt";
	string currentLine, name, income;
	float incomeTax;

	// Initialize tax and file objects
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
				name = tax.getName(currentLine);
				// Get tax income from current line
				income = tax.getIncome(currentLine);
				// Validate tax name and tax income
				if(tax.isValidName(name) && tax.isValidIncome(income)) {
					incomeTax = tax.getIncomeTax(atof(income.c_str()));
				} else {
					// Inform user there is an error with the name/income on line X
				}

			} else {
				// Inform user that the line length exceeds the limit
			}
		} else {
			// Inform user the line is empty
		}

	}

	// Close file
	file.closeFile();

	return 0;
}
