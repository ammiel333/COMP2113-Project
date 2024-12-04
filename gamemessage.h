#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H
#include <string>

void gameInstructions();

void printResults(std::vector<std::vector<char>> & charr, std::vector<std::vector<bool>> & found, std::vector<std::string> & tries, const int & present);

void endgame(const int & currentTry);

void earlyEndgame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match);

#endif 
