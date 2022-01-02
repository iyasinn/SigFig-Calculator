#pragma once

#include <sstream>

struct Element{

	// Constructors
	Element();
	Element(std::string input);
	Element(char x);

	// Variables
	std::string element;
	bool isNumber;

	// Tree Nodes
	Element* leftNode;
	Element* rightNode;

};

