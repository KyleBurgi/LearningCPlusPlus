#pragma once
#ifndef HANGMAN_HEADER
#define HANGMAN_HEADER

void displayMenu(char option);
void initHangman();
int playHangman(std::string currentWord);
bool continuePlay();
bool checkSolved(char answer[], std::string currentWord);
void printCurrentRound(char answer[], char guessInput, int mistakeCounter);
bool checkAlreadyGuessed(char guessInput, char guesses[], int guessCounter);
void printYouWin();
void printYouLose(std::string currentWord);

#endif