#include <iostream>
#include <fstream>
#include <string>


#include "inputOutput.h"

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
	std::ifstream inf{ "five_letter_words.txt" };

	if (!inf) 
	{
		std::cerr << "ERROR: Dictionary File Missing!\n";
		return -1;
	}
	int itr{ 0 };
	while (inf) 
	{
		std::string strInput;
		std::getline(inf, strInput);
		//std::cout << strInput << "\n";

		itr = itr + 1;
	}

	return itr;
}

void printYouWin()
{
	system("cls");
	std::cout << "########################################" << std::endl;
	std::cout << "# __   __           _    _ _       _   #" << std::endl;
	std::cout << "# \\ \\ / /          | |  | (_)     | |  #" << std::endl;
	std::cout << "#  \\ V /___  _   _ | |  | |_ _ __ | |  #" << std::endl;
	std::cout << "#   \\ // _ \\| | | || |/\\| | | '_ \\| |  #" << std::endl;
	std::cout << "#   | | (_) | |_| |\\  /\\  / | | | |_|  #" << std::endl;
	std::cout << "#   \\_/\\___/ \\__,_| \\ / \\/|_|_| |_(_)  #" << std::endl;
	std::cout << "#                                      #" << std::endl;
	std::cout << "########################################" << std::endl;
	return;
}

void printYouLose(std::string currentWord)
{
	system("cls");
	std::cout << "###############################################\n";
	std::cout << "# __   __            _                    _   #\n";
	std::cout << "# \\ \\ / /           | |                  | |  #\n";
	std::cout << "#  \\ V /___  _   _  | |     ___  ___  ___| |  #\n";
	std::cout << "#   \\ // _ \\| | | | | |    / _ \\/ __|/ _ \\ |  #\n";
	std::cout << "#   | | (_) | |_| | | |___| (_) \\__ \\  __/_|  #\n";
	std::cout << "#   \\_/\\___/ \\__,_| \\_____/\\___/|___/\\___(_)  #\n";
	std::cout << "#                                             #\n";
	std::cout << "###############################################\n\n";

	std::cout << "The word was: \t" << currentWord << "\n\n";
	return;
}


void printTop()
{
	std::cout << "################# \n";
	std::cout << "################# \n";
	std::cout << "###           ### \n";
	std::cout << "###           ### \n";
}

void printPillar() { std::cout << "###               \n"; }

void printHead(int mistakeCounter) 
{
	if (mistakeCounter > 0)
	{
		std::cout << "###            0  \n";
	}
	else
	{
		printPillar();
	}
}

void printMidsection(int mistakeCounter)
{
	if (mistakeCounter == 1)
	{
		std::cout << "###            |\n";
	}
	else if (mistakeCounter == 2)
	{
		std::cout << "###          / | \n";
	}
	else if (mistakeCounter >= 3)
	{
		std::cout << "###          / | \\ \t\n";
	}
	else
	{
		void printPillar();
	}
}

void printLegs(int mistakeCounter)
{
	if (mistakeCounter > 3)
	{
		std::cout << "###            |  \n";
	}
	if (mistakeCounter == 4)
	{
		std::cout << "###           / \n";
	}
	else if (mistakeCounter >= 5)
	{
		std::cout << "###           / \\ \n";
	}
	else
	{
		printPillar();
	}
}

void printBase(int mistakeCounter, char answer[])
{
	std::cout << "### \n";
	std::cout << "### \n";
	std::cout << "####################################\n";
	std::cout << "#####\t";
	for (int i = 0; i < 5; i++)
	{
		std::cout << answer[i];
	}
	std::cout << "\t##### Mistake: " << mistakeCounter << "/5 #\n";
	std::cout << "####################################\n";
}