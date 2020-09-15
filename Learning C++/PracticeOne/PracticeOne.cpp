// PracticeOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Purpose: Practice how to initialize variables, basic logic, and keyboard input.

#include <iostream>

int main()
{
    int a{ };
    int b{ };

    std::cout << "Enter a number: "; //ask user for a number
    std::cin >> a;

    std::cout << "Enter another number: ";
    std::cin >> b;

    std::cout << "You've entered " << a << " for a & " << b << " for b.\n";
    
    int c{ a + b };
    //std::cout << c << "\n"; //Note: << acts like a + operand for string logic. Prefer ‘\n’ over std::endl when outputting text to the console.
    std::cout << "a + b is equal to: " << c << std::endl; //std::endl is end of line break and will force next line.
    
    return 0;
}
