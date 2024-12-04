#ifndef WORDLE_H
#define WORDLE_H

#include <string>

bool isValid(std::string input);

void convertLowercase(std::string& input);

bool isWordInDictionary(const std::string& word, const std::string& dictionaryFile);

#endif // WORDLE_H
