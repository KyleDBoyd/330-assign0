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
	string delimiter = "\t";
	string income;
	income = s.substr(s.find(delimiter) + delimiter.length(), s.length);
	return income;
}

bool Tax::isValidName(string s)
{

}

bool Tax::isValidIncome(string s)
{
	
}