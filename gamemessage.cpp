#include "gamemessage.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
#include <unistd.h> 

void gameInstructions(){
    /*Game instructions*/
    std::cout << "Welcome to WORDLE game!\n\n";
    sleep(1);
    std::cout << "Wordle is a game which challenges you to guess a five-letter word.\n" ;
    std::cout << "You have 6 tries. Each guess should be a valid word.\n\n";
    sleep(1);
    std::cout << "The color of the letter will change to indicate how close your guess was.\n";
    std::cout << "A " << BLACK << B_GREEN << "GREEN" << RESET << " means that the letter is in the word AND in the right position.\n";
    std::cout << "A "  << BLACK << B_YELLOW << "YELLOW" << RESET << " means that the letter is in the word but NOT in the right position.\n";
    std::cout << "A " << BLACK << B_GRAY << "GRAY" << RESET << " means that the letter is NOT in the word.\n\n";
    sleep(1);
    std::cout << "Type \"hint\" to get one of the alphabets and its location randomly. You only have one hint. \n" << std::endl; 
    std::cout << "Type \"quit\" to quit the game. " << std::endl; 
    sleep(1); 
    std::cout << "Good luck!\n";
}

void endGame(const int & currentTry){
    std::cout << "You got the answer in " << currentTry << " tries !\n";
    switch(currentTry){
        case 1: std::cout << "Magnificent!"; break;
        case 2: std::cout << "Superb!"; break;
        case 3: std::cout << "Excellent!"; break;
        case 4: std::cout << "Outstanding!"; break;
        case 5: std::cout << "Great!"; break;
        case 6: std::cout << "Nice!"; break;
        }
    std::cout << "\n";
}                   

void earlyEndGame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match){
    if(input2 == "quit" && currentTry <= 6){
        std::cout << "It is unfortunate that you gave up!\n";
        }
    else if(present != -1){
        std::cout << "Unlucky!\n"; 
    }
    else if(currentTry == 6 && !match){
        std::cout << "You used up all the chances to guess the answer!\n";
        }
    sleep(1);
    std::cout << "The correct answer is ";
    for (size_t i = 0; i < word.length(); ++i) {
        std::cout << B_GREEN << " " << word[i] << " ";
    }
    std::cout << RESET << ".\n";
}
