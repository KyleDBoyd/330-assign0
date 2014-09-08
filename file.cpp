#include "file.h"

File::File(const char *c)
{
    filename = c;
}

File::~File()  
{

}

void File::openFile()
{
	// @TODO check for emptyh filename
	infile.open(filename);
	if(infile.fail()) {
		// Throw Error
	}
	return;
}

void File::closeFile()
{
	infile.close();
	return;
}

bool File::isEndOfFile() 
{
	if(infile.eof()) {
		return true;
	} else {
		return false;
	}
}

string File::getLine()
{
	getline(infile, currentLine);
	return currentLine;
}

bool File::isValidLineLength(string s)
{
	// @TODO Replace with constant
	if(s.length() <= 80) {
		return true;
	} else {
		return false;
	}
}
