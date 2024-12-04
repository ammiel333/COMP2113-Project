#ifndef CORRECTGUESS_H
#define CORRECTGUESS_H

#include <string>
#include <vector>

std::string CorrectGuess(const std::string& targetWord, const std::string& guess, std::vector<bool>& found, bool useColors);

#endif


// how to call the function:
// CorrectGuess(targetWord, guess, found, true)
// set third parameter to true if you want colored text
// if the third parameter is false, the text will not be coloured and instead be represented with color indicators like [G] or [Y] or [X]
// G is for green, Y for yellow, and X for grey. these are for when colored text output is not surrported. in this case, coloured output is supported but i left 
// the feature there because i found it interesting and it took time to implement
// also, no need to declare the found variable in the main function because it is declared here
