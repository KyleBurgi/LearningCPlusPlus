#pragma once

#ifndef INPUT_HEADER
#define INPUT_HEADER

int getDictionarySize();
char getUserInput();
void printYouWin();
void printYouLose(std::string currentWord);
void printPillar();
void printTop();
void printHead(int mistakeCounter);
void printMidsection(int mistakeCounter);
void printLegs(int mistakeCounter);
void printBase(int mistakeCounter, char answer[]);

#endif