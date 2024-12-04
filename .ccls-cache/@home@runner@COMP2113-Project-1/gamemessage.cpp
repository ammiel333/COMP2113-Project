#include "gamemessage.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector> 
#include <unistd.h> 

void gameInstructions(){
    /*Game instructions*/
    std::cout << "Welcome to WORDLE!\n" << "These are the rules of the game! \n\n";
    sleep(1);
    std::cout << "Wordle is a simple game in which you have to guess a five-letter word.\n" ;
    std::cout << "You have 6 tries only. Each 5-word guess must be a valid word.\n\n";
    sleep(1);
    std::cout << "The colour of the tile will change to show you how close your guess was.\n";
    std::cout << "A " << BLACK << B_GREEN << "GREEN" << RESET << " tile means that the letter is in the word AND in the right spot.\n";
    std::cout << "A "  << BLACK << B_YELLOW << "YELLOW" << RESET << " tile means that the letter is in the word BUT NOT in the right spot.\n";
    std::cout << "A " << BLACK << B_GRAY << "GRAY" << RESET << " tile means that the letter is NOT in the word.\n\n";
    sleep(1);
    std::cout << "Type \"quit\" anytime to quit the game. " << std::endl; 
    std::cout << "Type \"hint\" anytime to get one of the alphabets and its location randomly. You only have one hint. " << std::endl; 
    sleep(1);
    std::cout << "Good luck with your guesses!\n";
}

void endGame(const int & currentTry){
    if(currentTry == 1){    
        std::cout << "You got the answer with only " << currentTry << " try !\n";
    }
    std::cout << "You got the answer in " << currentTry << " tries !\n";
    switch(currentTry){
        case 1: std::cout << "Genius!"; break;
        case 2: std::cout << "Magnificent!"; break;
        case 3: std::cout << "Impressive!"; break;
        case 4: std::cout << "Splendid!"; break;
        case 5: std::cout << "Great!"; break;
        case 6: std::cout << "Phew!"; break;
        }
    std::cout << "\n";
}                   

void earlyEndGame(const int & currentTry, const std::string & input2, const int & present, const std::string & word, const bool & match){
    if(input2 == "quit" && currentTry <= 6){
        std::cout << "It's sad you gave up trying!\n";
        }
    else if(present != -1){
        std::cout << "You're too unlucky!\n"; 
    }
    else if(currentTry == 6 && match != 1){
        std::cout << "The 6 chances to guess the answer have been used up!\n";
        }
    sleep(1);
    std::cout << "The correct answer is " << word << ".\n";
}
