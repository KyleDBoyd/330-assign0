#ifndef CMD_H
#define CMD_H

// Libarary includes
#include <cstddef>
#include <iostream>
#include <stdexcept>

using namespace std;

class Cmd {

	// Class variables
    char *fileName;
    
    public:

        // Constructor
        Cmd(int argc, char *argv[]);
        // Destructor
        ~Cmd();
        // Get file name from command line argument
        char *getFileName();

};

#endif
