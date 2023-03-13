#pragma once

#include <iostream>
#include <algorithm>


using namespace std;

void enterCorrectGuess(string* userAnswer, const string correctAnswer, char* userLetter, string* usedLetters);

string enterWord();

bool isWord(const string word);

string wordToWORD(string word);

bool isFinalDecision(const short userAnswerSize, const short correctAnswerSize);

bool isLetterUsed(const string usedLetters, const char letter);

void show(const string usedLetters);

bool isLetterExist(const char letter);

bool isWordExist(const string word);

bool isSmallLetter(const char letter);

bool isBigLetter(const char letter);

char toUpper(char ch);



bool isLetterInWord(const string SECRET_WORD, const char letter);

string addLetterToAnswer(const string SECRET_WORD, const char guess, string userAnswer);

bool isWin(const string answer, const string correctAnswer);

void win(const short mistakes, const string answer,double time);

void lose(const string answer,double time);
