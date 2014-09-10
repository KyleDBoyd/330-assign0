#include "cmd.h"
Cmd::Cmd(int argc, char *argv[])
{

    fileName = argv[1];
    if (fileName == NULL) {
    	throw runtime_error("Empty file name.");
    }
}

Cmd::~Cmd()
{

}

char* Cmd::getFileName()
{
    return fileName;
}
