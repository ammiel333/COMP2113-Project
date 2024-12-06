#include <iostream>
#include <string>
#include <fstream>

bool length_validation(std::string input){
  if(input.length() != 5){
      return false;
}
bool isValid(std::string input){
  for (int i = 0; i < 5; i++){
    // 97 = a and 122 = z in lowercase
    if(input[i]<97 || input[i]>122){
      return false;
    }
  }
  return true;
}

void convertLowercase(std::string& input){
  for (int i = 0; i < 5; i++){
    // 65-90 is upper case letters
    if (input[i] < 97){
      input[i] += 32;
    }
  }
}

bool isWordInDictionary(const std::string& word, const std::string& dictionaryFile) {
    std::ifstream file(dictionaryFile);
    std::string dictWord;

    // Checking if the txt file can be opened
    if (!file.is_open()) {
        std::cerr << "Failed to open the dictionary file" << std::endl;
        return false;
    }

    // comparing the input with the words in the dictionary
    while (file >> dictWord) {
        if (dictWord == word) {
            return true; // The word is in the dictionary
        }
    }

    return false; // The word is not in the dictionary
}
