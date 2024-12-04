#include <iostream>
#include <string>
#include <vector>

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found, bool useColors) {
    std::string feedback; // declaring the feedback string to return
    std::vector<bool> used(targetWord.length(), false); // tracks which positions in the target word are "used" or "taken"

    // check for letters in the correct position (will be green)
    for (size_t i = 0; i < targetWord.length(); ++i) {
        if (guess[i] == targetWord[i]) {
            if (useColors) {
                feedback += "\033[32m"; // green colour for correct position
                feedback += guess[i];
                feedback += "\033[0m";  // reset the colour
            } else {
                feedback += "[G]"; // indicate the correct position without colour
                feedback += guess[i];
            }
            found[i] = true; // mark as found in the correct position
            used[i] = true;  // mark this position in the target word as used/taken
        } else {
            feedback += "_"; // temporary placeholder for now
        }
    }

    // check for letters in the wrong position (will be yellow)
    for (size_t i = 0; i < targetWord.length(); ++i) {
        if (feedback[i] == '_') { // if not already marked as correct
            bool isFound = false;

            // to check if the letter exists elsewhere in the target word because there can be more than use of the same letter in a word
            for (size_t j = 0; j < targetWord.length(); ++j) {
                if (!used[j] && guess[i] == targetWord[j]) {
                    isFound = true;
                    used[j] = true; // mark this position in the target word as used/taken
                    break;
                }
            }

            if (isFound) {
                if (useColors) {
                    feedback[i] = '\033'; // yellow colouring (wrong position but right letter)
                    feedback.append("\033");
