#include "Utility.h"
#include <string>

std::string calculator() {

	std::string input;
	std::cout << "Enter an expression! No spaces! \n\n";
	std::cin >> input;

	Element* expression = makeExpressionTree(input);
	std::string answer = evaluateExpression(expression);

	printExpression(expression);
	std::cout << "\n\nAnswer: " << answer << "\n";
	std::cout << "Sig figs: " << getSigFigs(answer) << "\n";
	std::cout << "Decimal Places: " << getDecimalPlaces(answer) << "\n\n";
}

Element* makeExpressionTree(std::string input) {

	Element* pointer;
	pointer = new Element();
	Element& node = *pointer;

	for (char x : "+-*/") {

		int index = input.find_last_of(x);

		if (index >= 0 && index < input.size()) {

			node = Element(x);
			node.leftNode = makeExpressionTree(input.substr(0, index));
			node.rightNode = makeExpressionTree(input.substr(index + 1, input.size()));

			return pointer;
		}
	}

	node = Element(input);
	return pointer;
}

void printExpression(Element* node) {
	if (node) {
		printExpression(node->leftNode);
		std::cout << node->element << " ";
		printExpression(node->rightNode);
	}
}

std::string evaluateExpression(Element* node) {

	if (node->isNumber) {
		return node->element;
	}

	std::string a = evaluateExpression(node->leftNode);
	std::string b = evaluateExpression(node->rightNode);

	switch (node->element[0]) {
		case('*'):
			return multiplyOrDivide(a, b, '*');
		case('/'):
			return multiplyOrDivide(a, b, '/');
		case('+'):
			return addOrSubtract(a, b, '+');
		case('-'):
			return addOrSubtract(a, b, '-');
	}
	
	return "";
}

//---------------------------------Helper Functions for evaluateExpresion------------------------------------------------------

std::string multiplyOrDivide(std::string a, std::string b, char operation) {

	int sigFigs = 0;

	if (getSigFigs(a) > getSigFigs(b)) {
		sigFigs = getSigFigs(b);
	}
	else {
		sigFigs = getSigFigs(a);
	}

	if (sigFigs == 0) {
		return "0";
	}

	switch (operation) {
	case('*'):
		a = std::to_string(stod(a) * stod(b));
		break;
	case('/'):
		a = std::to_string(stod(a) / stod(b));
		break;
	}

	int decimalIndex = a.find_first_of('.');

	// This is the case for if there is no need for the decimal
	std::string temp = a;
	temp.erase(decimalIndex, a.size());

	if (getSigFigs(temp) == sigFigs) {
		return temp;
	}
	else if (getSigFigs(temp) > sigFigs) {
		for (int i = 0; getSigFigs(temp) > sigFigs; i++) {
			temp[temp.size() - i - 1] = '0';
		}
		return temp;
	}

	temp += '.';
	// This is the case for if the decimal is there and we check the sigFigs
	if (getSigFigs(temp) == sigFigs) {
		return temp;
	}

	std::string addOn = a;
	addOn.erase(0, decimalIndex + 1);

	for (char x : addOn) {
		temp += x;
		if (getSigFigs(temp) == sigFigs) {
			return temp;
		}
	}
	
	return "";
}

std::string addOrSubtract(std::string a, std::string b, char operation) {

	int decimalPlaces = 0;

	if (getDecimalPlaces(a) > getDecimalPlaces(b)) {
		decimalPlaces = getDecimalPlaces(b);
	}
	else {
		decimalPlaces = getDecimalPlaces(a);
	}

	switch (operation) {
	case('+'):
		a = std::to_string(stod(a) + stod(b));
		break;
	case('-'):
		a = std::to_string(stod(a) - stod(b));
		break;
	}

	int decimalIndex = a.find_first_of('.');

	if (decimalPlaces == 0) {
		if (a[decimalIndex + 1] >= '5') {
			a[decimalIndex - 1]++;
		}
		a.erase(decimalIndex, a.size());
	}
	else {
		if (a[decimalIndex + decimalPlaces + 1] >= '5') {
			a[decimalIndex + decimalPlaces]++;
		}
		a.erase(decimalIndex + decimalPlaces + 1, a.size());
	}

	return a;
}

int getDecimalPlaces(const std::string& x) {

	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '.') {
			// Difference between index of decimal and final index
			// Since after a decimal every place is a decimal place
			return (x.size() - 1 - i);
		}
	}

	return 0;
}

int getSigFigs(std::string x) {

	int sigDigits = 0;
	bool decimal = false;
	bool numOccured = false;

	// Checks if there is a decimal
	if (x.find_first_of('.') >= 0 && x.find_first_of('.') < x.size()) {
		decimal = true;
	}

	for (int i = 0; i < x.size(); i++) {
		if (isdigit(x[i]) && x[i] != '0') {
			sigDigits++;
			numOccured = true;
		}
		else if (numOccured && x[i] == '0' && decimal) {
			sigDigits++;
		}
		else if (numOccured && x[i] == '0' && numberRight(x, i) != -1) {
			sigDigits++;
		}
	}

	return sigDigits;
}

int numberRight(std::string x, int index) {

	for (int i = index; i < x.size(); i++) {
		if (isdigit(x[i]) && x[i] != '0') {
			return i;
		}

	}

	return -1;



	
}

