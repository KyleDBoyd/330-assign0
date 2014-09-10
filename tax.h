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

    // Class variables
    struct taxBracket
    {
        int netIncomeMin;
        int netIncomeMax;
        int taxBaseAmount;
        int taxRate;
    };

    // Define tax bracket data
    /*taxBracket const taxBracketData[] = {
        {0, 35000, 0, 16},
        {35000, 70000, 5600, 22},
        {70000, 100000, 13300, 26},
        {100000, -1 , 21100, 29}
    };*/

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
