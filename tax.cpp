#include "tax.h"

Tax::Tax()
{

}

Tax::~Tax()  
{

}

string Tax::getName(string s)
{
	// @TODO - Replace delimeter with constant
	string delimiter = "\t";
	string name;
	name = s.substr(0, s.find(delimiter));
	return name;
}

string Tax::getIncome(string s)
{
	// @TODO - Replace delimeter with constant
	string delimiter = "\t";
	string income;
	int found;
	found = s.find(delimiter);
	if (found != std::string::npos) {
		income = s.substr(found);
	}
	return income;
}

bool Tax::isValidName(string s)
{
	/*regex reg("[-a-zA-Z0-9., ]+");
	if(!s.empty() && regex_match(s, reg)) {
		return true;
	} else { 
		return false;
	}*/
	return true;
}

bool Tax::isValidIncome(string s)
{
	/*regex reg("[0-9]+.[0-9][0-9]");
	if(!s.empty() && regex_match(s, reg)) {
		return true;
	} else { 
		return false;
	}*/
	return true;
}

float Tax::getIncomeTax(float f)
{

}

float Tax:calculateIncomeTax(float taxBaseAmount, float netIncome, float incomeBaseAmount, float TaxRate)
{
	return taxBaseAmount + (netIncome - incomeBaseAmount) * taxRate;
}
