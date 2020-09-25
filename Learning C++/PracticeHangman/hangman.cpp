
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime>

#include "inputOutput.h"
#include "hangman.h"

//global variable for the dictionary with a static size so we don't have to worry about deallocating it later
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
    //currently doesn't need to be implemented
    //gets dictionary size
    //int dictionarySize{ getDictionarySize() };
    //std::cout << "The size of the dictionary is: \t" << dictionarySize << "\n";

    int dictionarySize{ 5758 };

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
    std::string currentWord = dictionary[abs(std::rand()) % dictionarySize];

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

//could probably use hash on this.
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


    //These output the game to the console
    printTop();
    printHead(mistakeCounter);
    printMidsection(mistakeCounter);
    printLegs(mistakeCounter);
    printBase(mistakeCounter, answer);
    
}



bool checkSolved(char answer[], std::string currentWord)
{
    //Iterates through both the array and string to see if they are the same
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

    //loops if not y or n
    while (input != 'y' && input != 'n')
    {
        std::cout << "Would you like to play again? y/n: \t";
        input = getUserInput();
    }

    if (input == 'y')
        return true;
    
    return false;
}