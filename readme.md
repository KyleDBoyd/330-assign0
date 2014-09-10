Kyle Boyd

564867695

CSCI 331

Assignment 0

Specification
==============

Input
--------------

Your program will read in a series of lines, one at a time. Each line is to contain two fields separated by a tab character and be no more than 80 characters. The first field is a string, the taxpayer's name, matching the regular expression:

        [-a-zA-Z0-9., ]+

and the second a number, the taxpayer's net income, matching the regular expression:

        [0-9]+\.[0-9][0-9]

Tax computation
--------------

This is taken more or less directly from the Canadian 2004 Income Tax Schedule 1.

|INCOME                                          |TAX BASE AMOUNT|MARGINAL TAX RATE     |
|------------------------------------------------|---------------|----------------------|
|If the net income is $35,000 or less $0.00:     |$0.00          |16%                   |
|More than $35,000, but not more than $70,000    |$5,600.00      |22%                   |
|More than $70,000, but not more than $100,000   |$13,300.00     |26%                   |
|More than $100,000                              |$21,100.00     |9%                    |

Tax is computed by locating the appropriate column and finding the corresponding income base amount, tax base amount and marginal tax rate. The former is the lowest income for which the column applies (one of $0.00, $35,000.00, $70,000.00, $100,000.00), the latter are read directly from the table. These values are used to compute the federal income tax as follows:

income tax = tax base amount + (net income - income base amount) * marginal tax rate
Example 1: net income $25,000.00

income base amount: $0.00
tax base amount: $0.00
marginal tax rate: 16%

Giving the following: income tax = 0.00 + (25,000.00 - 0.00) * 16% = $4000.00
Example 2: net income $72,000.00

income base amount: $70,000.00
tax base amount: $13,300.00
marginal tax rate: 26%

Giving the following: income tax = 13,300.00 + (72,000.00 - 70,000.00) * 26% = $13,820.00
Output

For each valid input line, a line of the following form should be printed to standard output:

Name String: $tax amount

Lines not meeting the input specification should generate an error message to standard error indicating the line number and nature of the problem.

File List
==============
- cmd.cpp
- cmd.h 
- file.cpp
- file.h
- tax.cpp
- tax.h
- main.cpp
- makefile 
- tax.txt
- readme.md

Example Executions
==============
Run the "make" command to compile the program 

	$ make
	g++ -std=gnu++11 -c main.cpp
	g++ -std=gnu++11 -c file.cpp 
	g++ -std=gnu++11 -c tax.cpp 
	g++ -std=gnu++11 -c cmd.cpp 
	g++ -std=gnu++11 -o app main.o file.o tax.o cmd.o 

Run "./app" followed by a text file. Lines with the correct input format will return the taxpayer's name followed by their income tax.

	$ ./app tax.txt
	Test UserA: $4000
	Test UserB: $13820
	Test UserC: $21100

More example executions to demonstrate the error handling:

	$ ./app
	An error occured: Empty file name.

	$ ./app random.txt
	An error occured: File failed to open.


Test Cases
==============

Tax computation
--------------
1. Test UserA	123456
2. Test UserB	0
3. Test UserC	-1000
4.	5000	
5. Test UserE	35000
6. Test UserF	70000
7. Test UserG	100000
8. Test UserH	100001
9. Test UserI	25000
10. Test UserJ	72000
11. TestUser1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890	$123456

Output
--------------
1. Test UserA: $27902.2
2. Test UserB: $0
3. Negative income input on line 3
4. 
5. Test UserE: $93600
6. Test UserF: $195100
7. Test UserG: $21100
8. Test UserH: $21100.3
9. Test UserI: $4000
10. Test UserJ: $13820
11. Line length exceeds the limit of 80 characters on line 11
