#include <iostream>
#include <string>
#include <vector>
\\ use namespace std? depends on main code

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found) {
    std::string feedback;

    for (size_t i = 0; i < targetWord.length(); ++i) {
        char guessChar = guess[i];
        char targetChar = targetWord[i];

        if (guessChar == targetChar) {
            feedback += "<span style='color: green'>" + std::string(1, guessChar) + "</span>";
            found[i] =true; 
        } else if (targetWord.find(guessChar) != std::string::npos) {
            feedback += "<span style='color: yellow'>" + std::string(1, guessChar) + "</span>";
        } else {
            feedback += "<span style='color: grey'>" + std::string(1, guessChar) + "</span>";
        }
    }

    return feedback;
}
