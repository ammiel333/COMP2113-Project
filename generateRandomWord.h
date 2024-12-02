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
