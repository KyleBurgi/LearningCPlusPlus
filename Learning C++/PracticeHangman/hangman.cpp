
#include <iostream>
#include "input.h"
#include "hangman.h"


void displayMenu(char option)
{
    do {
        
        std::cout << "Choose one of the following options and press enter.... i, q, p\n";
        option = getUserInput();
        //Assuming this is running on Windows
        system("cls");
        switch (option)
        {
            case 'i':
            {
                std::cout << "Print Menu\n";
                break;
            }
            case 'p':
            {
                std::cout << "Starting your game of Hangman!\n";
                playHangman();

                break;
            }
            case 'q':
            {
                std::cout << "Quitting";
                break;
            }

            default:
                std::cout << "Invalid option: Please choose one of the following options and press enter.... i, q, p\n";
        }
    } while (option != 'q');
    return;
}

void playHangman() {
    int dictionarySize{ getDictionarySize() };

    std::cout << "The size of the dictionary is: \t" <<dictionarySize;
    return;

}