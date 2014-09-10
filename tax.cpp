#include "tax.h"

Tax::Tax()
{
	// Initialize tax bracket data
    taxBracketData[0] = {0, 35000, 0, 16};
    taxBracketData[1] = {35000, 70000, 5600, 22};
    taxBracketData[2] = {70000, 100000, 13300, 26};
    taxBracketData[3] = {100000, -1 , 21100, 29};
}

Tax::~Tax()  
{
	// @TODO Delete taxBracketData array
}

string Tax::getName(string s)
{
	string name;
	name = s.substr(0, s.find(delimiter));
	return name;
}

string Tax::getIncome(string s)
{
	string income;
	int found;
	found = s.find(delimiter);
	if (found != std::string::npos) {
		income = s.substr(found + delimiter.length());
	}
	return income;
}

bool Tax::isValidName(string s)
{
	/*regex reg("[a-zA-Z0-9., ]+", regex_constants::ECMAScript);
	if(!s.empty() && regex_match(s, reg)) {
		return true;
	} else { 
		return false;
	}*/
	return true;
}

bool Tax::isValidIncome(string s)
{
	/*regex reg("[0-9]+.[0-9][0-9]", regex_constants::ECMAScript);
	if(!s.empty() && regex_match(s, reg)) {
		return true;
	} else { 
		return false;
	}*/
	return true;
}

float Tax::getIncomeTax(float netIncome)
{
	bool foundBracket = false;
	if(netIncome < 0) {
		return -1;
	} else if (netIncome == 0) {
		return 0;
	} else {
		for (int i=0; i < sizeof(taxBracketData) && !foundBracket; i++) {
			if (((taxBracketData[i].netIncomeMax == -1) || (taxBracketData[i].netIncomeMax != -1 && netIncome <= taxBracketData[i].netIncomeMax)) && netIncome > taxBracketData[i].netIncomeMin) {
				return calculateIncomeTax(taxBracketData[i].taxBaseAmount, netIncome, taxBracketData[i].netIncomeMin, taxBracketData[i].taxRate);
			}
		}
	}
}

float Tax::calculateIncomeTax(float taxBaseAmount, float netIncome, float incomeBaseAmount, float taxRate)
{
	return taxBaseAmount + (netIncome - incomeBaseAmount) * taxRate / 100;
}
