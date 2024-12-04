#include <iostream>
#include <string>
#include <vector> 
#include "correctguess.h" 
#include "generateRandomWord.h"
#include "wordle.h"
#include "hint.h" 
#include "gamemessage.h"
using namespace std; 

int main() {
    string dictionaryFile = "dictionary.txt";
    const int maxAttempts = 6; 
    int attempt = 1; 
    string inputWord; 

    //Load word list from the dictionary file 
    WordList wordList = loadWords(dictionaryFile);

    //Generate random answer from the word List 
    string answer = generateRandomWord(wordList); 
    convertLowercase(answer); 

    
    bool guessedCorrectly = false, hintUsed = false; 
    vector <bool> found(answer.size(), false); 

    //Display game instructions 
    gameInstructions();  

    while (attempt <= maxAttempts){
        cout << "\nInput word for attempt " << attempt <<"/" << maxAttempts << ": "<< endl; 
        cin >> inputWord;

        //if user quits the game
        if (inputWord == "quit"){
            earlyEndGame(attempt, inputWord, -1, answer, guessedCorrectly); 
            freeWordList(wordList);
            return 0; 
        }

        //If user requests a hint 
        if (inputWord == "hint"){
            if(!hintUsed){
                hintUsed = true; 
                int hintIndex = hintLocation(found); 
                
                if(hintIndex == -1){
                    cout << "All the letters of the answer have already been revealed. No hint available. " << endl; 
                } else {
                    cout << "Hint: The letter '"<< B_GREEN << BLACK << " " << answer[hintIndex] << " " << RESET << "' is at position " << hintIndex + 1 << "." << endl;
                }
            } else {
                cout << "Hint is already used." << endl;
            }
            continue; 
        }

        //convert user input to lowercase
        convertLowercase(inputWord); 

        //check if word is valid 
        if (!isValid(inputWord)){
            cout << "Invalid input, please try again." << endl; 
            continue; 
        }

        //check if the word is in dictionary 
        if (!isWordInDictionary(inputWord, dictionaryFile)){
            cout << "Not in the wordlist, please try again." << endl; 
            continue; 
        }
        
        //if the input is correct
        if(inputWord == answer){
            guessedCorrectly = true; 
            hintUsed = true; 
            endGame(attempt); 
            freeWordList(wordList);
            return 0; 
        }
        
        //provide feedback for incorrect guess
        string feedback = CorrectGuess(answer, inputWord, found, true); 
        cout << feedback << endl; 
        attempt++; 
    }

    //when the user wasn't able to find the answer 
    if (!guessedCorrectly){
        earlyEndGame(attempt, inputWord, -1, answer, guessedCorrectly); 
    }

    freeWordList(wordList);
    return 0;
}

