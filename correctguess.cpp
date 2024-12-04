#include <string>
#include <vector>
#include <iostream>

// ANSI color codes for terminal output
const std::string GREEN = "\033[32m";   // Green for correct position
const std::string YELLOW = "\033[33m"; // Yellow for correct letter, wrong position
const std::string GREY = "\033[90m";   // Grey for incorrect letter
const std::string RESET = "\033[0m";   // Reset to default color

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found, bool useColors) {
    std::string feedback;                        // The feedback string to return
    std::vector<bool> used(targetWord.size(), false); // Tracks letters in the target word already matched (green/yellow)

    // Initialize the feedback string
    feedback.resize(targetWord.size(), '_');

    // First pass: Check for green matches (correct letter and correct position)
    for (size_t i = 0; i < targetWord.size(); ++i) {
        if (guess[i] == targetWord[i]) { // Correct letter in the correct position
            if (useColors) {
                feedback[i] = 'G'; // Placeholder for green
            } else {
                feedback[i] = 'G'; // Non-color placeholder for green
            }
            found[i] = true;  // Mark the letter as matched for green
            used[i] = true;   // Mark this letter in the target word as used
        }
    }

    // Second pass: Check for yellow matches (correct letter, wrong position)
    for (size_t i = 0; i < targetWord.size(); ++i) {
        if (feedback[i] == 'G') { // Skip green matches
            continue;
        }

        // Look for the letter in the target word (wrong position)
        bool isYellow = false;
        for (size_t j = 0; j < targetWord.size(); ++j) {
            if (!used[j] && guess[i] == targetWord[j]) { // Correct letter, but not used yet
                isYellow = true;
                used[j] = true; // Mark this letter in the target word as used
                break;
            }
        }

        if (isYellow) {
            if (useColors) {
                feedback[i] = 'Y'; // Placeholder for yellow
            } else {
                feedback[i] = 'Y'; // Non-color placeholder for yellow
            }
        } else { // If not green or yellow, it must be grey
            if (useColors) {
                feedback[i] = 'X'; // Placeholder for grey
            } else {
                feedback[i] = 'X'; // Non-color placeholder for grey
            }
        }
    }

    // Third pass: Build the final feedback string with colors or plain text
    std::string finalFeedback;
    for (size_t i = 0; i < feedback.size(); ++i) {
        if (feedback[i] == 'G') { // Green
            finalFeedback += "[G]" + std::string(1, guess[i]); 
        } else if (feedback[i] == 'Y') { // Yellow
            finalFeedback += "[Y]" + std::string(1, guess[i]);
        } else { // Grey
            finalFeedback += "[X]" + std::string(1, guess[i]);
            }
        }
    }

    return finalFeedback;
}
