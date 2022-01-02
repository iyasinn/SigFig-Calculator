#include <iostream>
#include "Utility.h"

int main() {

	std::cout << "Welcome to the sig fig calculator! \n\n";

	while (true) {

		std::cout << "1. Enter a calculation \n2. Exit \nChoice: ";

		int input;
		std::cin >> input;

		std::cout << "\n";

		switch (input) {
			case(1):
				calculator();
				break;
			case(2):
				std::cout << "Have a good day! \n";
				return 0;
			default:
				std::cout << "Invalid input!\n\n";
				break;
		}

	}

	return 0;
}



