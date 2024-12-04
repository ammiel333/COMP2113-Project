#ifndef GAMEMESSAGE_H
#define GAMEMESSAGE_H
#include <string>
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */

#define B_BLACK   "\033[40m"    /* Black */
#define B_RED     "\033[41m"    /* Red */
#define B_GREEN   "\033[42m"    /* Green */
#define B_YELLOW  "\033[43m"    /* Yellow */
#define B_BLUE    "\033[44m"    /* Blue */
#define B_MAGENTA "\033[45m"    /* Magenta */
#define B_CYAN    "\033[46m"    /* Cyan */
#define B_WHITE   "\033[47m"    /* White */
#define B_GRAY "\033[100m"      /* Gray */


void gameInstructions();

void endGame(const int & currentTry);

void earlyEndGame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match);

#endif 
