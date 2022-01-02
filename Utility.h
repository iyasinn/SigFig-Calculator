#pragma once
#include <iostream>
#include "Element.h"

// Main function for doing calculations
void calculator();

//* Makes a binary tree that can hold the expression
// For example, if the expression is 1 + 2 * 3
// It will create the following binary tree:
//         + 
//       /   \
//      1     *
//          /   \
//         2     3
// It maintains right associativity for operations with the 
// highest precedence operators being at the bottom 
//*
Element* makeExpressionTree(std::string input);

// Prints the expression contained within a tree
void printExpression(Element* node);

// Evaluates the expression within the tree from the bottom up
std::string evaluateExpression(Element* node);

// Takes two strings, adds or subtracts them based on the operation, which can be '+' or '-', 
// and adjusts the decimal place.
std::string addOrSubtract(std::string a, std::string b, char operation);

// Takes two strings, multiply or divides them based on the operatino, which can be '*' or '/'
// and adjusts the signficant digits
std::string multiplyOrDivide(std::string a, std::string b, char operation);

// Returns the number of signficant digits in a number that is stored as a string
int getSigFigs(std::string x);

// Returns the number decimal places in a nubmer that is stored as a string
int getDecimalPlaces(const std::string& x);

// Checks if there is a number to the right of a number
// If there is, it returns the index of the number, otherwise it returns -1
int numberRight(std::string x, int index);
