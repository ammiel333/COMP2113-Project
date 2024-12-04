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
    WordList wordList = loadWords(dictionaryFile);
    string answer = generateRandomWord(wordList); 
    bool guessedCorrectly = false, hintUsed = false; 
    vector <bool> found = {false, false, false, false, false}; 

    gameInstructions();  

    while (attempt <= maxAttempts){
        cout << "Input word for attempt " << attempt <<"/" << maxAttempts << ": "<< endl; 
        cin >> inputWord;

        //if user quits the game
        if (inputWord == "quit"){
            earlyEndGame(attempt, inputWord, -1, answer, guessedCorrectly); 
            freeWordList(wordList);
            return 0; 
        }

        if (inputWord == "hint"){
            if(!hintUsed){
                hintUsed = true; 
                int hintIndex = hintLocation(found); 
    
                if(hintIndex == -1){
                    cout << "You already know all letters of the answer." << endl; 
                    continue; 
                }
                cout << "Hint: The letter '"<< answer[hintIndex] << "'is at postion " << hintIndex + 1 << "." << endl; 
            }
            else {cout << "Hint is already used." << endl;}
            continue; 
        }

        convertLowercase(inputWord); 

        //check if word is valid 
        if (!isValid(inputWord)){
            cout << "Invalid input, please try again." << endl; 
            continue; 
        }

        //check if the word is not in dictionary 
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

