#infdef FILE_H
#define FILE_H

class File {
    public:
        // Constructor
        file();
        // Destructor
        ~file();
        // Opens file. Throw error if it fails to open.
        void openFile();
        // Close file. Throw error if it fails to close.
        void closeFile();
         
    private:
        // Check the taxpayer's name input.
        boolean checkName(string s);
        // Check the taxpayer's net income input.
        boolean checkIncome(string s);
        // Check file input line length to ensure it is not over 80 characters.
        boolean checkLineLength(string s);
}
