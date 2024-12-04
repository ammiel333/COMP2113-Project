#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H
#include <string>

constexpr const char* BLACK = "\033[30m"; /* Black */
constexpr const char* B_GREEN = "\033[42m"; /* Green */
constexpr const char* B_YELLOW = "\033[43m"; /* Yellow */
constexpr const char* B_GRAY = "\033[100m"; /* Gray */
constexpr const char* RESET = "\033[0m"; /* Reset */

void gameInstructions();

void endGame(const int & currentTry);

void earlyEndGame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match);

#endif
