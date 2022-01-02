# SigFig-Calculator

You can run this code at the following repl:
https://replit.com/@Intricon/Significant-Digit-Calculator#main.cpp
<br/>
This calculator can take a mathematical expression and provide an answer that accounts for the rules of significant digits, and also the rules of decimal places that are associated with any of the four basic operations: addition, multiplication, subtraction, addition.


Calculation rules:
1. When multiplying or dividing two numbers, the new number of signficant digits will be those of the number with the smallest number of signficant digits.
2. When adding or subtracting two numbers, the new number of decimal places will be those of the number with the least number of decimal places.

Significant Digit Rules:
1. All non-zero numbers are significant.
2. Any zero that is in between two non-zero numbers is signficant.
3. Leading zeros are not signficant.
4. Trailing zeros are signficant if they occure after a number and if there is a decimal point. Otherwise, they are also not significant.


Examples:

1.0001   --->   5 sig figs <br/>
1230     --->   4 sig figs <br/>
1230.    --->   5 sig figs <br/>
101      --->   3 sig figs <br/>
1010     --->   3 sig figs <br/>
