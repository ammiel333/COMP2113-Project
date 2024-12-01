#include "wordle.h"

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
    std::cout << "Type \"quit\" anytime to quit the game. " << endl; 
    std::cout << "Type \"hint\" anytime to get one of the alphabets and its location randomly. You only have one hint. " << endl; 
    sleep(1);
    std::cout << "Good luck with your guesses!\n";
}

void printResults(std::vector<std::vector<char>> & charr, std::vector<std::vector<bool>> & found, std::vector<std::string> & tries, const int & present){ /*printing out user input of tries*/
    std::cout << "*****************\n";
    int len1 = charr.size();
    for (int i=0; i<len1; i++){
        std::cout << "| ";
        int len2 = charr[i].size();
        for(int s=0; s<len2; s++){
            
            if((charr[i][s] == 'G') && (found[i][s] == 1)){ /*correct char and correct pos*/
                std::cout << BLACK << B_GREEN;
            }
            else if((charr[i][s] != 'G') && (found[i][s] == 1)){    /*user input char correct but wrong pos*/
                std::cout << BLACK << B_YELLOW;
            }
            else{   
                int len3 = charr.size() - 1;
                if(i == len3 && s == present){
                    std::cout << BLACK << B_MAGENTA;
                }
                else{
                    std::cout << BLACK << B_GRAY;    /*user input char incorrect*/
                }
            }
            std::cout << tries[i][s] << RESET << " |" ;
        }
        std::cout << "\n*****************\n";
    }
    
};

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
