#ifndef CMD_H
#define CMD_H

using namespace std;

class Cmd {

    fileName;
    
    public:

        // Constructor
        Cmd(int argc, char *argv[]);
        // Destructor
        ~Cmd();
        // Get file name from command line argument
        getFileName();

};

#endif
