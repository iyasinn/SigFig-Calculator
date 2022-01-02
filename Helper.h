#pragma once

#include "Element.h"

int Element::getDecimalPlaces(std::string x) {

	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '.') {
			// Difference between index of decimal and final index
			// Since after a decimal every place is a decimal place
			return (x.size() - 1 - i);
		}
	}

	return 0;

}

int Element::getSigFigs(std::string x) {

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
			numOccured = 1;
		}
		else if (numOccured && x[i] == '0' && decimal) {
			sigDigits++;
		}
		else if (numOccured && x[i] == '0' && numberRight(x, i)) {
			sigDigits++;
		}
	}

	return sigDigits;
}

bool Element::numberRight(std::string x, int index) {

	for (int i = index; i < x.size(); i++) {
		if (isdigit(x[i]) && x[i] != '0') {
			return true;
		}

	}
	return false;
}
