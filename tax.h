#ifndef TAX_H
#define TAX_H
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Tax {

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
        float getIncomeTax(float f);
    private:
        // Calculate income tax
	float calculateIncomeTax(float taxBaseAmount, float netInome, float incomeBaseAmount, float taxRate);
};

#endif
