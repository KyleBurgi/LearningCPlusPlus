
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime>

#include "input.h"
#include "hangman.h"

std::string dictionary[5758];


void displayMenu(char option)
{
    do {
        
        //print menu here
        std::cout << "Welcome to Hangman!\n";
        std::cout << "input the following letter to choose that option:\n";
        std::cout << "Enter i: Information\n";
        std::cout << "Enter p: Play Hangman\n";
        std::cout << "Enter q: Quit the application\n";

        option = getUserInput();
        //Assuming this is running on Windows
        system("cls");
        switch (option)
        {
            case 'i':
            {
                std::cout << "This program was written by Kyle Burgi in a poor attempt to learn C++. \n";
                std::cout << "He'll try to fix bugs as they arise and add new features.\n";
                std::cout << "He refuses to make any promises though.\n";
                std::cout << "Copyright 2020 || github.com/kyleburgi || kyleburgi.com\n\n";

                std::cout << "Press enter to continue...\n";
                std::cin.get();

                break;
            }
            case 'p':
            {
                std::cout << "Starting your game of Hangman!\n";
                initHangman();

                break;
            }
            case 'q':
            {
                std::cout << "Quitting";
                break;
            }

            default:
                std::cout << "Invalid option: Please choose a correct option\n";
        }
    } while (option != 'q');
    return;
}

void initHangman() {
    //gets dictionary size
    int dictionarySize{ getDictionarySize() };
    //std::cout << "The size of the dictionary is: \t" << dictionarySize << "\n";

    // implements dictionary
    std::ifstream inf{ "five_letter_words.txt" };
    if (!inf)
    {
        std::cerr << "ERROR: Dictionary File Missing!\n";
        return;
    }

    //normally I wouldn't hardcode a value you like this, but I haven't figured out how to deallocate memory yet in C++

    if (inf.is_open())
    {
        for (int i = 0; i < dictionarySize; i++)
            inf >> dictionary[i];
    }
    int win = 0;
    int gamesPlayed = 0;
    do {
    //chooses random word from dictionary
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string currentWord = dictionary[abs(std::rand()) % dictionarySize + 1];

    //for debug
    //std::cout << "The current word is: " << currentWord << "\n";
    //std::cout << "The current word is: " << currentWord[0] << "\n";

    win = win + playHangman(currentWord);
    } while (continuePlay());
}

int playHangman(std::string currentWord)
{

    int mistakeCounter = 0;
    int guessCounter = 0;
    bool correctGuess = false;
    char guessInput;
    char guesses[26];
    char answer[5] = {'_','_','_','_','_'}; //5 is the length of all words in the dictionary

    do 
    {
        std::cout << "Input your guess: \t";
        guessInput = getUserInput();

        //checks if a char was already guessed
        if (checkAlreadyGuessed(guessInput, guesses, guessCounter)) {
            continue;
        }
        
        //inputs  the guess into the guess array and increases counter
        guesses[guessCounter] = guessInput;
        guessCounter = guessCounter + 1;

        //checks char against word
        //fills in answer array if correct
        for (int i = 0; i < (int) currentWord.length(); i++)
        {
            if (answer[i] != '_') //skips iteration if it is already filled
            {
                continue;
            }
            else if (guessInput == currentWord[i]) //checks input against word at this iteration
            {
                correctGuess = true;
                answer[i] = guessInput;
            }
        }
        if (!correctGuess)
        {
            mistakeCounter = mistakeCounter + 1;

            if (mistakeCounter > 5)
                break;
        }

        printCurrentRound(answer, guessInput, mistakeCounter);

        //DEBUG
        /*
        std::cout << "DEBUG\n";
        std::cout << "CURRENT GUESS:\t" << guessCounter << "\n";
        std::cout << "CORRECT GUESS:\t" << correctGuess << "\n";
        std::cout << "MISTAKE COUNTER\t" << mistakeCounter << "\n";
        std::cout << "CHECK SOLVED:\t" << checkSolved(answer, currentWord) << "\n";
        */

        //reset checks
        correctGuess = false;

    } while (!checkSolved(answer, currentWord));

    if (checkSolved(answer, currentWord))
    {
        printYouWin();
        return 1;
    }
    else
    {
        printYouLose(currentWord);
        return 0;
    }

    return 0;
}

bool checkAlreadyGuessed(char guessInput, char guesses[], int guessCounter)
{
    for (int i = 0; i < guessCounter; i++)
    {
        if (guessInput == guesses[i])
            return true;
    }

    return false;
}

void printCurrentRound(char answer[], char guessInput, int mistakeCounter) 
{
    system("cls");
    std::cout << "YOUR GUESS: \t" << guessInput << "\n";
    //std::cout << "The current hangman looks like:\t";

    for (int i = 0; i < 5; i++) 
    {
        std::cout << answer[i];
    }
    std::cout << "\n";

    std::cout << "################# \n";
    std::cout << "################# \n";
    std::cout << "###           ### \n";
    std::cout << "###           ### \n";
    if (mistakeCounter > 0)
    {
        std::cout << "###            0  \n";
    }
    else 
    {
        std::cout << "###               \n";
    }
    
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
        std::cout << "###               \n";
    }
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
    std::cout << "###               \n";
    }

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

bool checkSolved(char answer[], std::string currentWord)
{
    for (int i = 0; i < currentWord[i]; i++)
    {
        if (answer[i] != currentWord[i])
            return false;
    }
    return true;
}

bool continuePlay() {
    std::cout << "Would you like to play again? y/n: \t";
    char input = getUserInput();

    while (input != 'y' && input != 'n')
    {
        std::cout << "Would you like to play again? y/n: \t";
        input = getUserInput();
    }

    if (input == 'y')
        return true;
    
    return false;
}