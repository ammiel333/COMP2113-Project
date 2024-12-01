#include <iostream>
#include <string>
#include "correctguess.h" 
#include "generateRandomWord.h"
#include "wordle.h"
#include "hint.h" 
using namespace std; 

int main() {
    string dictionaryFile = "dictionary.txt";
    const int maxAttempts = 6; 
    int attempt = 1; 
    string inputWord; 
    string answer = generateRandomWord(dictionaryFile); 
    bool guessedCorrectly = false, hintUsed = false; 
    vector <bool> found = {false, false, false, false, false}; 
    
    cout << "Welcome to Wordle! You get 6 chances to guess a 5-letter word. " <<endl;
    cout << "Write \"hint\" anytime to get one of the alphabets and its location randomly. You only have one hint. " << endl; 

    while (attempt <= maxAttempts){
        cout << "Input word for attempt " << attempt <<"/" << maxAttempts << ": "<< endl; 
        cin >> inputWord;

        if (inputWord == "hint"){
            if(!hintUsed){
                hintUsed = true; 
                int hintIndex = hintLocation(found); 
    
                if(hintIndex == -1){
                    cout << "You have already found the answer." << endl; 
                    continue; 
                }
                char hintLetter = answer[hintIndex]; 
                cout << "Hint: The letter '"<< hintLetter << "'is at postion " << hintIdex + 1 << "." << endl; 
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
        if (inputWord == answer){
            guessedCorrectly = true; 
            hintUsed = true; 
            switch (attempt) {
                case 1: 
                cout << "Genius! You guessed the word \"" << answer << "\" on your first try. " << endl; break;
                case 2: 
                cout << "Magnificant! You guessed the word \"" << answer << "\" on your second try." << endl; break;
                case 3: 
                cout << "Impressive! You guessed the word \"" << answer << "\" on your third try." << endl; break; 
                case 4: 
                cout << "Splendid! You guessed the word \"" << answer << "\" on your fourth try." << endl; break;
                case 5: 
                cout << "Great! You guessed the word \"" << answer << "\" on your fifth try." << endl; break;
                case 6: 
                cout << "Phew! You guessed the word \"" << answer << "\" on your sixth try." << endl; break;
            }
            break; 
        }
        
        //provide feedback to the user
        string feedback = CorrectGuess(answer, inputWord, found); 
        cout << feedback << endl; 
        attempt++; 
    }

    //when the user wasn't able to find the answer 
    if (!guessedCorrectly){
        cout << "The answer was: " << answer << endl; 
    }
    
    return 0;
}

