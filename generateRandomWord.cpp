#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

string generateRandomWord(const string& fileName) {
    
    string word;
    // Generate a vector to contain all possible words
    vector<string> words;
    
    ifstream fin;
    fin.open(fileName);
    
    // Check whether file is opened > Exit if fail
    if (fin.fail()) {
        
        exit(1);
        
    }
    
    while(fin>>word) {
        
        // Add word from dictionary.txt to vector words
        words.push_back(word);
        
    }
    
    fin.close();
    
    // Generate ramdom number
    // Initialize seeds
    srand(statistic_cast<unsigned int>(time(nullptr)));
    
    int randomIndex = rand() % words.size();
    
    return words[randomIndex];
}

int main() {
    
    string fileName = "dictionary.txt";
    string randomString = generateRandomWord(fileName);
    
}
