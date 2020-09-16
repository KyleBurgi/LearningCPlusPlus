#include <iostream>

int getInteger() {
	std::cout << "Enter an integer: ";
	int returnInteger;
	std::cin >> returnInteger;
	return returnInteger;
}

int addTwoIntegers(int x, int y) {
	if (x == NULL || y == NULL) { return 0; } //returns zero if either value is null
	return x + y;
}