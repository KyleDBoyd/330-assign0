#ifndef TAX_H
#define TAX_H

// Library includes
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Tax {

    // Class constants
    const string delimiter = "\t";
    static const int numTaxBrackets = 4;

    // Class variables
    struct taxBracket
    {
        int netIncomeMin;
        int netIncomeMax;
        int taxBaseAmount;
        int taxRate;
    };

    // Initialze tax bracket data array
    taxBracket taxBracketData[numTaxBrackets];

    public:
        // Constructor
        Tax();
        // Destructor
        ~Tax();
    	// Gets taxpayer's name from provided string
    	string getName(string s);
    	// Gets taxpayer's net income from provided string
    	string getIncome(string s);
    	// Check the taxpayer's name input.
        bool isValidName(string s);
        // Check the taxpayer's net income input.
        bool isValidIncome(string s);
        // Get income tax based on the provided tax amount
        float getIncomeTax(float netIncome);
    private:

        // Calculate income tax
	    float calculateIncomeTax(float taxBaseAmount, float netIncome, float incomeBaseAmount, float taxRate);
};

#endif
