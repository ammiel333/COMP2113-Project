#ifndef GENERATE_RANDOM_WORD_H
#define GENERATE_RANDOM_WORD_H

#include <string>
#include <random>

struct WordList {
  std::string* words;
  int size;

};

WordList loadWords(const std::string& fileName);

void freeWordList(WordList& wordList);

std::string generateRandomWord(WordList& wordList);

#endif

/* How to call the function: 

loadWords(fileName)
Specify the file name that you want to load the words from 
It will load the words in that specified file then store in dynamically allocated allay 

freeWordList(wordList)
Parameter wordList is a dnamically allocated array that store the words for Wordle game
This function can be called to free the allocated memory for wordList 

generateRandomWord(wordList)
Paramter is wordList
By using wordList, this function return the randomly generated word which will be the answer of the game
*/
