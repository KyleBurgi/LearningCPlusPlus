// PracticeHangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "input.h"
#include "hangman.h"

int main()
{
    //upon starting the program we go straight to the menu and force-feeding it the "introduction" option
    std::cout << "Welcome to Hangman! Press enter to start!";
    std::cin.get();
    char option{ };
    displayMenu(option);
    return 0;
}




