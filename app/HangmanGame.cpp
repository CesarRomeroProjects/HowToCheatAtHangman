#include "HangmanGame.hpp"
#include <iostream>
#include <string>
#include <sstream>


HangmanGame::HangmanGame(std::istream &in, unsigned wordSize)
: wordsRemaining{}, pattern{""}
{
    std::string line, word;
    std::stringstream ss;

    while(  getline(in, line) )
    {
        ss.clear();
        ss << line;
        while( ss >> word )
        {
            if( word.size() == wordSize)
            {
                wordsRemaining.addWord( word );
            }
        }
    }
    for(unsigned i{0}; i < wordSize; i++)
    {
        pattern += "-"; 
    }
    // There are better ways to do that.
}



// This function WILL NOT be used in testing your program.
// You are welcome to make changes to it if you want.
// HOWEVER, IF THIS CAUSES YOUR PROGRAM TO NOT COMPILE, WE WILL BE UNABLE TO GRADE IT
void HangmanGame::playGame()
{
    // set this to true and re-build to have it run with showing all possible words remaining.
    // CAUTION:  YOU MIGHT NOT WANT TO DO THIS WITH LARGE WORD LISTS!
    constexpr bool SHOW_WORDS_REMAINING = true; 


    // the game ends when the player has guessed the word -- no dashes remain.
    while( pattern.find('-') != std::string::npos )
    {
        std::cout << "Pattern: " <<  getPattern() << std::endl;
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;
        guessLetter( guess );
        if( SHOW_WORDS_REMAINING )
        {
            std::cout << "\tWords Remaining: " << std::endl;
            std::cout << "\t-----------------" << std::endl;
            for(size_t k{0}; k < wordsRemaining.getSize(); k++)
            {
                std::cout << "\t" << wordsRemaining.wordAt(k) << std::endl;
            }
            std::cout << "\t-----------------" << std::endl;
        }
    }

    std::cout << "You are right, the word was " << getPattern() << std::endl;
} 



bool HangmanGame::guessLetter(char guess)
{
    WordList wordFamilies[500]; // Create an array of WordList objects (Capacity: 500)
    size_t largestFamilyPos{0};
    size_t largestFamilySize{0};
  
    // How To Cheat At Hangman Algorithm
    for (size_t wordPos{0}; wordPos < possibleWordsRemaining(); wordPos++) 
    {
        std::string &word{wordsRemaining.wordAt(wordPos)};
        std::string wordPattern{pattern};

        // Update wordPattern if the guess is found within the word.
        for (size_t charPos{0}; charPos < word.length(); charPos++)
        {
            if (word[charPos] == guess)
                wordPattern[charPos] = guess; 
        }

        // If word pattern exists in wordFamilies, add it to that WordList.
        bool isInFamily{false};
        for (size_t wordFamilyPos{0}; wordFamilyPos < MAX_FAMILIES; wordFamilyPos++)
        {
            std::string wordFamilyPattern{wordFamilies[wordFamilyPos].wordAt(0)};
            size_t wordFamilySize{wordFamilies[wordFamilyPos].getSize()};

            if (wordFamilySize > 0 && wordPattern == wordFamilyPattern) 
            {
                wordFamilies[wordFamilyPos].addWord(word);
                isInFamily = true;
                break;
            }

            else if (wordFamilies[wordFamilyPos].getSize() == 0)
                break;
        }

        // If word pattern doesn't exist in wordFamilies, add it.
        if (! isInFamily) 
        {
            for (size_t wordFamilyPos{0}; wordFamilyPos < MAX_FAMILIES; wordFamilyPos++) 
            {
                if (wordFamilies[wordFamilyPos].getSize() == 0) 
                {
                    wordFamilies[wordFamilyPos].addWord(wordPattern);
                    wordFamilies[wordFamilyPos].addWord(word);
                    break;
                }
            }
        }
    }

    // Find the largest word family in wordFamilies.
    for (size_t wordFamilyPos{0}; wordFamilyPos < MAX_FAMILIES; wordFamilyPos++) 
    {
        size_t wordFamilySize{wordFamilies[wordFamilyPos].getSize()};

        // Update size and position of largest family.
        if (wordFamilySize > largestFamilySize) {
            largestFamilySize = wordFamilySize;
            largestFamilyPos = wordFamilyPos;
        }

        else if (wordFamilySize == 0)
            break;
    }

    // Setup to move the largest family in wordFamilies into wordsRemaining.
    if (wordFamilies[largestFamilyPos].getSize() > 0) 
    {
        pattern = wordFamilies[largestFamilyPos].wordAt(0);
        wordFamilies[largestFamilyPos].removeWord(0);
        largestFamilySize = wordFamilies[largestFamilyPos].getSize();
    }

    // Remove all the words in the wordsRemaining array.
    while (wordsRemaining.getSize() != 0) {
        wordsRemaining.removeWord(0);
    }
    
    // Update wordsRemaining with the new words remaining.
    for (size_t wordFamilyPos{0}; wordFamilyPos < wordFamilies[largestFamilyPos].getSize(); wordFamilyPos++) {
        std::string &remainingWord{wordFamilies[largestFamilyPos].wordAt(wordFamilyPos)};
        wordsRemaining.addWord(remainingWord);
    }

    return pattern.find(guess) != std::string::npos;
}

const std::string & HangmanGame::getPattern()
{
    return pattern; 
}

size_t HangmanGame::possibleWordsRemaining() const
{
    return wordsRemaining.getSize();
}
