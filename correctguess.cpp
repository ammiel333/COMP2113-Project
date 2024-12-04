#include <iostream>
#include <string>
#include <vector>
// accounts for both coloured text output and not coloured output
// latter case will print things like [G] to indicate correct letters and so on

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found, bool useColors) {
    std::string feedback; // declaring the feedback string to return
    std::vector<bool> used(targetWord.length(), false); // tracks which positions in the target word are "used" or "taken"

    // First pass: Check for letters in the correct position (will begreen)
    for (size_t i = 0; i < targetWord.length(); ++i) {
        if (guess[i] == targetWord[i]) {
            if (useColors) {
                feedback += "\033[32m"; // green color for correct position
                feedback += guess[i];
                feedback += "\033[0m";  // reset the color
            } else {
                feedback += "[G]"; // indicate the correct position without color
                feedback += guess[i];
            }
            found[i] = true;  // mark as found in the correct position
            used[i] = true;   // mark this position in the target word as used/taken
        } else {
            feedback += "_"; // temporary placeholder for now
        }
    }

    // Second pass: Check for letters in the wrong position (will be yellow)
    for (size_t i = 0; i < targetWord.length(); ++i) {
        if (feedback[i] == '_') { // if not already marked as correct
            bool isFound = false;

            // Check if the letter exists elsewhere in the target word
            for (size_t j = 0; j < targetWord.length(); ++j) {
                if (!used[j] && guess[i] == targetWord[j]) {
                    isFound = true;
                    used[j] = true; // mark this position in the target word as used/taken
                    break;
                }
            }

            if (isFound) {
                if (useColors) {
                    feedback[i] = '\033'; // adding yellow coloring (wrong position but right letter)
                    feedback += "\033[33m"; // yellow color
                    feedback += guess[i];
                    feedback += "\033[0m";  // reset color
                } else {
                    feedback += "[Y]"; // indicate wrong position with correct letter without color
                    feedback += guess[i];
                }
            } else {
                // Third pass: Handle incorrect letters (will be grey)
                if (useColors) {
                    feedback += "\033[90m"; // grey color for incorrect letter
                    feedback += guess[i];
                    feedback += "\033[0m";  // reset color
                } else {
                    feedback += "[X]"; // indicate wrong letter without color
                    feedback += guess[i];
                }
            }
        }
    }

    return feedback;
}


int main() {
    // Hard code the target word
    std::string targetWord = "HELLO";

    // Input a guess word
    std::string guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;

    // Initialize the vector to track found positions
    std::vector<bool> found(targetWord.length(), false);

    // Call the CorrectGuess function with colors enabled
    std::string feedbackColored = CorrectGuess(targetWord, guess, found, true);
    std::cout << "Feedback (Colored):\n" << feedbackColored << std::endl;



    return 0;
}
