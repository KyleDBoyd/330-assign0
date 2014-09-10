#include "file.h"

File::File(char *c)
{
    filename = c;
}

File::~File()  
{

}

void File::openFile()
{
	infile.open(filename);
	if (infile.fail()) {
		throw runtime_error("File failed to open");
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
	lineNumber++;
	return currentLine;
}

bool File::isValidLineLength(string s)
{
	if (s.length() <= lineCharacterLimit) {
		return true;
	} else {
		return false;
	}
}

bool File::isEmptyLine(string s)
{
	return s.empty();
}

int File::getLineNumber()
{
	return lineNumber;
}
