#include <iostream>
#include <string>
#include "correctguess.h" 
#include "generateRandomWord.h"
#include "wordle.h"
using namespace std; 

int main() {
    string dictionaryFile = "dictionary.txt";
    const int maxAttempts = 6; 
    int attempt = 1; 
    string answer = generateRandomWord(dictionaryFile); 
    cout << "Welcome to Wordle! You get 6 chances to guess a 5-letter word. " 

    while (attempt <= maxAttepts){
        cout << "Input word for attempt " << attempt << <<"/" << maxAttempts << ": "<< endl; 
        cin >> inputWord;

        convertLowercase(inputword); 

        //check if word is valid 
        if (!isValid(inputWord){
            cout << "Invalid input, please try again." << endl; 
        }

        //check if the word is not in dictionary 
        if (!isWordInDictionary(inputWord, dictionaryFile)){
            cout << "Not in the wordlist, please try again." << endl; 
        }
        //if the input is correct
        if (inputWord == answer){
            switch (attempt) {
                case 1: 
                cout << "Genius! You guessed the word \"" << answer << "\" on your first try. " endl;
                break; 
                case 2: 
                cout << "Magnificant! You guessed the word \"" << answer << "\" on your second try." endl;
                break; 
                case 3: 
                cout << "Impressive! You guessed the word \"" << answer << "\" on your third try." endl;
                break; 
                case 4: 
                cout << "Splendid! You guessed the word \"" << answer << "\" on your fourth try." endl;
                break; 
                case 5: 
                cout << "Great! You guessed the word \"" << answer << "\" on your fifth try." endl;
                break; 
                case 6: 
                cout << "Phew! You guessed the word \"" << answer << "\" on your sixth try." endl;
                break; 
            }
            break; 
        }
        //feedback 
        string feedback = CorrectGuess(inputWord, answer); 
        cout << "Feedback: " feedback << endl; 
        attempt++; 
    }

    //when the user wasn't able to find the answer 
    cout << "The answer was: " << answer << endl; 
    return 0;
}
