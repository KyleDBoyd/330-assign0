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
	// @TODO check for empty filename
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
	return infile.eof();
}

string File::getLine()
{
	getline(infile, currentLine);
	return currentLine;
}

bool File::isValidLineLength(string s)
{
	// @TODO Replace 80 with constant
	if(s.length() <= 80) {
		return true;
	} else {
		return false;
	}
}

bool File::isEmptyLine(string s)
{
	return s.empty();
}
