#ifndef TAX_H
#define TAX_H

using namespace std;

class Tax {

    public:
    	string getName();
    	// Check the taxpayer's name input.
        bool isValidName(string s);
        // Check the taxpayer's net income input.
        bool isValidIncome(string s);
};

#endif