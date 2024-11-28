#include <iostream>
#include <string>
#include <fstream>

bool isValid(std::string input){
  if(input.length() != 5){
    return false;
  }
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

    // 파일을 열 수 있는지 확인
    if (!file.is_open()) {
        return false;
    }

    // 사전 파일에서 단어를 읽어 입력된 단어와 비교
    while (file >> dictWord) {
        if (dictWord == word) {
            return true; // 단어가 사전에 존재함
        }
    }

    return false; // 단어가 사전에 없음
}
