# Wordle Game

Welcome! Wordle is a popular game that requires the player to guess a 5-letter word. The player has 6 chances, and feedback is provided for each attempt.

---

## Team Members 
Jennifer0903 - Jaeyoung Shim (3035899266) <br />
codeoflassitude - Kashaf Shahid (3036181719) <br />
ammiel333 - Sungmin Kim (3036136001) <br />
dkyng1125 - Dokyung Yum (3036135631) <br />

---

## How To Play

1. Input a 5-letter word.
2. Feedback will be provided based on your guess:
   - **Green**: The letter is correct and in the right position.
   - **Grey**: The letter is incorrect.
   - **Yellow**: The letter is correct but in the wrong position. 
3. Guess the word within 6 trials to win the game.

---

## Features Included

It includes a list of features included in the code by each team member. 

---

## 1. Jaeyoung Shim (3035899266) 
### 1) hint.cpp

This file contains the code for selecting a random position of a letter in the target word that has not yet been guessed correctly.

* **Identify unfound letters in the vector**: It scans through the found vector and identify indices of letter that have not been guessed yet. This is dynamically allocated in a a new data structure. 
* **Randomly select a hint index**: It randomly selects one index from the vector that stores location of unfound letters.
* **Dynamic memory management for temporary storage**: The notfound vector temporarily store the indices of unfound letter.
* **Program codes in multiple files**: hint.cpp is called in the main.cpp file based on the user's input. 
 
### 2) main.cpp

This file manages the game flow by handling user interactions, validating input, and make use of all the other files to serve as the core driver fo the Wordle game. 

* **Random word selection**: It implements generateRandomWord() function to select a random word from the dictionary and stores it in a string. 
* **Input Validation**: It calls the isValid() and isWordInDictionary() functions for validation.
* **Hints**: hintLoacation() function is called by the user's request to randomly generate a position that the player hasn't guessed correctly and provide the letter and its position.
* **Feedback on Guesses**: Feedback is provided for each guess using the CorrectGuess function.
* **Mutliple Attempts**: The player is allowed up to 6 attempts through using the data structure attempt to store the current attempt number.
* **Endgame Scenarios**: Both success and failures are handled using endGame() and enaryEndGame() functions.
* **Modular Design**: This program utilizes multiple files for different functions of the game.

## 2. Sungmin Kim (3036136001)
### 3) wordle.cpp

This file contains the code to check the format of the input and converts it into lowercase if it is not. It also checks if the input is a valid word.

* **Input Format Checking**: isValid() function checks if the user input is in a right format; It checks if the input is a valid 5-letter word that exists, and checks if any of the letters are in upper case.
* **Converting to lowercase**: convertLowercase() function checks if the input is in upper case, and converts it into lower case when upper case letter is found.
* **Checking if the input is a valid word**: isWordInDictionary() function is a boolean function that checks if the word input is a valid word. It is done by checking if the word is in the dictionary file where the 5-letter word is saved.

### 4) wordle.h

This file is a header file corresponding to wordle.cpp file, which declares the functions in the wordle.cpp so that they can be used in a separate main.cpp file.

It declares the following functions:
* isValid()
* convertLowercase()
* isWordInDictionary()
  
---

## 3. Dokyung Yun (3036135631)
### 5) generateRandomWord.cpp

This file contains the code to load words from the specified text file and store the words in the array using dynamic memory management. Then, generate the random word which become a answer of the game. 

* **WordList Structure**: structure WordList holds the dynamically allocated array of words and the number of words from the file. 
* **Load words from the file**: loadWords() function loads the words from the specified file and dynamically allocate the words in the array with the size of number of words in the file. 
* **Free the memory**: freeWordLists() function frees the memory allocated for WordList structure.
* **Generate random word for game**: generateRandomWord() function return a random word from the array of wordList by generating random index using Mersenne Twister engine and uniform distribution.

### 6) generateRandomWord.h

This file is a header file corresponding to generateRandomWord.cpp file, which declares a structure and functions in the generateRandomWord.cpp so that they can be used in a separate generateRandomWord.cpp file.

It declares the following structure and functions:
* struct WordList
* loadWords()
* freeWordList()
* generateRandomWord()

---


