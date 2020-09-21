#include <iostream>
#include <fstream>
#include <string>

#include "input.h"

char getUserInput() 
{
	char userInput{ '0' };
	std::cin >> userInput;
	
	while ((getchar()) != '\n'); //clears input buffer

	//checks to see if userInput is not a letter
	//we don't check for specific input, just it being a letter
	if (!isalpha(userInput))
	{
		std::cout << "Please use a letter";
		getUserInput();
	}

	return userInput;
}

int getDictionarySize()
{
	std::ifstream inf{ "engmix.txt" };

	if (!inf) 
	{
		std::cerr << "ERROR: Dictionary File Missing!";
		return -1;
	}
	int itr{ 0 };
	while (inf) 
	{
		std::string strInput;
		std::getline(inf, strInput);
		std::cout << strInput << "\n";

		itr = itr + 1;
	}

	return itr;
}

char* getDictionary() 
{
	return NULL;
}