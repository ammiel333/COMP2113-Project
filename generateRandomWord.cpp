#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// Define a structure WordList to hold a list of words in the file
struct WordList {

    string* words;    // Pointer to the dynamically allocated array of words 
    int size;         // Number of words in the array 

};

// Function to load words from file into an array
WordList loadWords(const string& fileName) {

    WordList wordList;    // Create a instance of WordList
    ifstream fin;         // Create file input stream
    fin.open(fileName);   // Open the file

    // Check the file can be opened
    // If file opening fails, exit
    if (fin.fail()) {

        exit(1);
        
    }

    int count = 0;    // Initialize the variable to count the number of words in the file
    string word;      // Define a variable to store each word of the file

    // Reads words from the file and counts
    while (fin >> word) {

        count ++; // Increment the count for each word read

    }

    // Preparation for re-reading the file 
    fin.clear();        // Clear the stream state
    fin.seekg(0);       // Reset the file pointer to the beginning of the file

    // Allocate memory for dynamic array to store words
    // Allocate an array of strings with size of count
    wordList.words = new string[count];    // Pointer points the start point of the dynamic array
    wordList.size = count;                 // Variable to store the number of words

    // Initialize the index of array
    int index = 0;

    // Reads words from the file and store them according to the index of dynamically allocated array
    while(fin >> word) {

        wordList.words[index++] = word;    // Increment the index for each word
        
    }

    // Close the file
    fin.close();

    // Return the WordList containing the words from the file
    return wordList;
    
}

// Function to free the allocated memory for WordList
void freeWordList(WordList& wordList) {

    delete[] wordList.words;

}

// Function to generate a random word from the wordList
string generateRandomWord(WordList& wordList) {

    // Initialize Mersenne Twister engine random number generator
    // Current time as seed for diverse random numbers
    static mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    
    // Create an uniform distributon to limit the range of random numbers within 0 and wordList.size - 1
    uniform_int_distribution<> dis(0, wordList.size - 1);

    // Generate a random index and return the word at that index in the array of WordList
    return wordList.words[dis(gen)];

}
