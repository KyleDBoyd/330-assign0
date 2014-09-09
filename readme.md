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

INCOME                                          TAX BASE AMOUNT       MARGINAL TAX RATE
If the net income is $35,000 or less $0.00:     $0.00                 16%
More than $35,000, but not more than $70,000    $5,600.00             22%
More than $70,000, but not more than $100,000   $13,300.00            26%
More than $100,000                              $21,100.00            29%

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
