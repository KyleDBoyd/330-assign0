// Library includes
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

// Class includes
#include "file.h"
#include "tax.h"
#include "cmd.h"



using namespace std;

int main(int argc, char *argv[])
{

	try {

		// Initialize cmd object with command line arguments
		Cmd cmd(argc, argv);

		// Variables
		string currentLine, name, income;
		float incomeTax;

		// Initialize file and tax objects
		File file(cmd.getFileName());
		Tax tax;

		// Open file
		file.openFile();

		// Process file
		while (!file.isEndOfFile()) {

			// Get next line
			currentLine = file.getLine();

			// Make sure line isn't empty
			if (!file.isEmptyLine(currentLine)) {

				// Make sure line length isn't over 80 characters
				if (file.isValidLineLength(currentLine)) {

					// Get tax name from current line
					name = tax.getName(currentLine);

					// Get tax income from current line
					income = tax.getIncome(currentLine);

					// Validate tax name
					if (tax.isValidName(name)) {

						// Validate tax income
						if (tax.isValidIncome(income)) {

							// Get income tax
							incomeTax = tax.getIncomeTax(atof(income.c_str()));

							// Check for invalid income
							if (incomeTax == -1) {
								cout << "Negative income input on line " << file.getLineNumber() << endl;
							} else {
								cout << name << ": $" << incomeTax << endl;
							}

						// Invalid tax income
						} else {
							cout << "Invalid income input on line " << file.getLineNumber() << endl;
						}

					// Invalid tax name
					} else {
						cout << "Invalid name input on line " << file.getLineNumber() << endl;
					} 
				
				// Invalid line length
				} else {
					cout << "Line length exceeds the limit of 80 characters on line " << file.getLineNumber() << endl;
				}

			// Empty line
			} else {
				cout << "Line " << file.getLineNumber() << " is empty." << endl;
			}
		}

		// Close file
		file.closeFile();

	} catch (exception &e) {
		cout << "An error occured: " << e.what() << endl;
	}

	return 0;
}
