# Wordle Game

Welcome! Wordle is a popular game that requires the player to guess a 5-letter word. The player has 6 chances, and feedback is provided for each attempt.

---

## Team Members 
Jennifer0903 - Jaeyoung Shim (3035899266) <br />
codeoflassitude - Kashaf Shahid (3036181719) <br />
ammiel333 - Sungmin Kim (3036136001) <br />
dkyng1125 - Dokyung Yun (3036135631) <br />
youarethexie - To Tsz Yeung (3036063010)  <br />

---

## How To Play

1. Input a 5-letter word.
2. Feedback will be provided based on your guess:
   - **Green**: The letter is correct and in the right position.
   - **Grey**: The letter is incorrect.
   - **Yellow**: The letter is correct but in the wrong position. 
3. Guess the word within 6 trials to win the game.

---

## Compilation and Execution Instruction 

### 1. Prerequisite Installations

- `Clang++` (or other C++11-compatible compiler)
- `Make`: to process the Makefile


### 2. Compilation
   
* ``make``: It compiles all `.cpp` files into object files and link them to create the `wordle` executable.


### 3. Wordle Execution
   
* ``./wordle``: The command starts the wordle game. 

### 4. Debug Build
   
* ``make wordle-debug``: This builds the debug version of the program.

* ``./wordle-debug``: This runs the debug version.

* ``gdb ./wordle-debug``: This allows users to debug with `gdb`. 
   
### 5. Clean Build
   
* ``make clean``: The command removes `wordle`, `wordle-debug` executables and all `-o` object files

---

## Features Included

The following are the lists of features implemented by each team member in the code.


## 1. Jaeyoung Shim (3035899266) 
### 1) `hint.cpp`

This file contains the code for selecting a random position of a letter in the target word that has not yet been guessed correctly.

* **Identify unfound letters in the vector**: It scans through the `found` vector and identify indices of letter that have not been guessed yet. This is dynamically allocated in a a new data structure. 
* **Randomly select a hint index**: It randomly selects one index from the vector that stores location of unfound letters.
* **Dynamic memory management for temporary storage**: The `notfound` vector temporarily store the indices of unfound letter.
* **Program codes in multiple files**: `hint.cpp` is called in the `main.cpp` file based on the user's input.

### 2) `hint.h`

This is a header file for `hint.cpp` file. 

It declares the following function: 
* `hintLocation()`
 
### 3) `main.cpp`

This file manages the game flow by handling user interactions, validating input, and make use of all the other files to serve as the core driver fo the Wordle game. 

* **Random word selection**: It implements `generateRandomWord()` function to select a random word from the dictionary and stores it in a string. 
* **Input Validation**: It calls the `isValid()` and `isWordInDictionary()` functions for validation.
* **Hints**: `hintLoacation()` function is called by the user's request to randomly generate a position that the player hasn't guessed correctly and provide the letter and its position.
* **Feedback on Guesses**: Feedback is provided for each guess using the `CorrectGuess()` function.
* **Mutliple Attempts**: A `while` loop enables the player to have up to 6 attempts using the `int` data structure to store the current attempt number.
* **Endgame Scenarios**: Both success and failures are handled using `endGame()` and `earlyEndGame()` functions.
* **Modular Design**: This program utilizes multiple files for different functions of the game.

## 2. Sungmin Kim (3036136001)
### 4) `wordle.cpp`

This file contains the code to check the format of the input and converts it into lowercase if it is not. It also checks if the input is a valid word.

* **Input Format Checking**: `isValid()` function checks if the user input is in a right format; It checks if the input is a valid 5-letter word that exists, and checks if any of the letters are in upper case.
* **Converting to lowercase**: `convertLowercase()` function checks if the input is in upper case, and converts it into lower case when upper case letter is found.
* **Checking if the input is a valid word**: `isWordInDictionary()` function is a boolean function that checks if the word input is a valid word. It is done by checking if the word is in the dictionary file where the 5-letter word is saved.

### 5) `wordle.h`

This file is a header file corresponding to wordle.cpp file, which declares the functions in the wordle.cpp so that they can be used in a separate main.cpp file.

It declares the following functions:
* `isValid()`
* `convertLowercase()`
* `isWordInDictionary()`
  
---

## 3. Dokyung Yun (3036135631)
### 6) `generateRandomWord.cpp`

This file contains the code to load words from the specified text file and store the words in the array using dynamic memory management. Then, generate the random word which become a answer of the Wordle game. 

* **WordList Structure**: structure WordList holds the dynamically allocated array of words and the number of words from the text file. 
* **Load words from the file**: `loadWords()` function loads the words from the specified file and dynamically allocate the words in the array with the size as number of words in the file. 
* **Free the memory**: `freeWordLists()` function frees the memory allocated for WordList structure.
* **Generate random word for game**: `generateRandomWord()` function return a random word from the array of wordList by accessing the dynamically allocated array using the random index generated by Mersenne Twister engine and uniform distribution.

### 7) `generateRandomWord.h`

This file is a header file corresponding to generateRandomWord.cpp file, which declares a structure and functions in the generateRandomWord.cpp so that they can be used in a separate generateRandomWord.cpp file.

It declares the following structure and functions:
* `struct WordList`
* `loadWords()`
* `freeWordList()`
* `generateRandomWord()`

---

## 4. Kashaf Shahid (3036181719)
### 8) `correctguess.cpp`

This file contains code that provides feedback for a player's guessed word compared to the randomly generated word, which is the target word, by analyzing the correctness of each character. The function returns feedback in three forms:

* **Green**: Letters are in the correct position
* **Yellow**: Letters that exist in the target word but are in the wrong position
* **Grey**: Letters that do not exist in the target word

This color-coded feedback is useful for guiding the player toward the correct word over several attempts. The function supports both colored terminal output (using ANSI escape codes) and plain-text feedback for non-color environments.

Important Features of the Code:
* **Handles Repeated Letters Properly:** the function ensures that repeated letters in the guess do not incorrectly match more times than they appear in the target word.
* **Colored Output for Terminal and Non-Color Output for Compatibility:** the function uses ANSI escape codes to provide feedback in green, yellow, and grey when useColors is set to true. For environments where colors are not supported, the function provides plain text with [G], [Y], and [X] indicators for green, yellow, and grey feedback, respectively.
* **Dynamic and Scalable:** the function dynamically adapts to words of any length.

### 9) `correctguess.h`
This is a header file for `correctguess.cpp` file.

It declares the following function:
`CorrectGuess()`

---

## 5. To Tsz Yeung (3036063010)

### 10) `gamemessage.cpp`

This file contains code that provides the game message when the player enters the game and finishs the game.

* **Game Instructions**: uses function `gameInstructions()` to show the instruction when the player enters the game
* **End Game Message**: use function `endGame()` to show the endgame message if the player successfully beats the game
* **Early EndGame Message()** : use function `earlyEndGame()` to show the earlyendgame message if the player fails the game no matter by quitting or by losing

### 11) `gamemessage.h`

This is a header file for `gamemessage.cpp` file.

It declares the following function:
`gameInstructions()`
`endGame()`
`earlyEndGame()`

---
