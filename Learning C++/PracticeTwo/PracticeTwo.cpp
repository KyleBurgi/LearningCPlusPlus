// PracticeTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Purpose: Take the previous lesson and add upon it by using methods.

#include <iostream>

int getNumberFromUser();
int addNumbers(int a, int b);

int main()
{
    int a{ getNumberFromUser() };
    int b{ getNumberFromUser() };

    int c{ addNumbers(a, b) };

    std::cout << a << " + " << b << " = " << c << "\n";

    return 0;
}

int getNumberFromUser()
{
    int inputNumber;

    std::cout << "Please enter a whole number: ";
    std::cin >> inputNumber;
    std::cout << "You have entered: " << inputNumber << "\n";

    return inputNumber;
}

int addNumbers(int a, int b)
{
    int c{ a + b };
    return c;
}
