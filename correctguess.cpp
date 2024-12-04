#include <string>
#include <vector>
#include <iostream>

// ANSI color codes for terminal output
const std::string GREEN = "\033[32m";   // green for correct position
const std::string YELLOW = "\033[33m"; // yellow for correct letter, wrong position
const std::string GREY = "\033[90m";   // grey for incorrect letter
const std::string RESET = "\033[0m";   // reset to default color

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found, bool useColors) {
    std::string feedback;                        // the feedback string to return
    std::vector<bool> used(targetWord.size(), false); // tracks letters in the target word already matched (green/yellow)

    // initialize the feedback string
    feedback.resize(targetWord.size(), '_');

    // first pass: check for green matches (correct letter and correct position)
    for (size_t i = 0; i < targetWord.size(); ++i) {
        if (guess[i] == targetWord[i]) { // correct letter in the correct position
            if (useColors) {
                feedback[i] = 'G'; // placeholder for green
            } else {
                feedback[i] = 'G'; // non-color placeholder for green
            }
            found[i] = true;  // mark the letter as matched for green
            used[i] = true;   // mark this letter in the target word as used/taken
        }
    }

    // second pass: check for yellow matches (correct letter, wrong position)
    for (size_t i = 0; i < targetWord.size(); ++i) {
        if (feedback[i] == 'G') { // skip green matches
            continue;
        }

        // look for the letter in the target word (wrong position)
        bool isYellow = false;
        for (size_t j = 0; j < targetWord.size(); ++j) {
            if (!used[j] && guess[i] == targetWord[j]) { // correct letter, but not used yet
                isYellow = true;
                used[j] = true; // mark this letter in the target word as used
                break;
            }
        }

        if (isYellow) {
            if (useColors) {
                feedback[i] = 'Y'; // placeholder for yellow
            } else {
                feedback[i] = 'Y'; // non-color placeholder for yellow
            }
        } else { // if not green or yellow, it must be grey
            if (useColors) {
                feedback[i] = 'X'; // placeholder for grey
            } else {
                feedback[i] = 'X'; // non-color placeholder for grey
            }
        }
    }

    // third pass: build the final feedback string with colors or plain text. the actual product of this function
    std::string finalFeedback;
    for (size_t i = 0; i < feedback.size(); ++i) {
        if (feedback[i] == 'G') { // green
            if (useColors) {
                finalFeedback += GREEN + std::string(1, guess[i]) + RESET;
            } else {
                finalFeedback += "[G]" + std::string(1, guess[i]);
            }
        } else if (feedback[i] == 'Y') { // yellow
            if (useColors) {
                finalFeedback += YELLOW + std::string(1, guess[i]) + RESET;
            } else {
                finalFeedback += "[Y]" + std::string(1, guess[i]);
            }
        } else { // grey
            if (useColors) {
                finalFeedback += GREY + std::string(1, guess[i]) + RESET;
            } else {
                finalFeedback += "[X]" + std::string(1, guess[i]);
            }
        }
    }

    return finalFeedback;
}
