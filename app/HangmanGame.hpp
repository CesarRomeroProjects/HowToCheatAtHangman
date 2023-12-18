#ifndef __45C_HANGMAN_GAME_HPP
#define __45C_HANGMAN_GAME_HPP

#include <fstream>  // you DO NOT need to know how this works yet.  It is used in some provided code
#include <string>
#include "WordList.hpp"

class HangmanGame
{


public:


    HangmanGame(std::istream &in, unsigned wordSize); 
    // this populates the initial wordsRemaining to be the words of the given size from the file provided.
    // This will also initialize pattern to be all dashes of the proper length.
    // This function is provided for you.
    
    
    void playGame(); 
    // Plays the game.  This function is provided for you and WILL NOT be tested.
    // However, be sure that IF you change it, you do not cause your code to not compile!




    // The next function is called when the user has just guessed this letter.
    // Update the wordRemaining to be as large as it can be, and update the pattern to fit 
    // with the information the user now knows.  

    // Return true if and only if the guessed letter is now part of the pattern 
    //      (i.e., if we told the player that yes, that letter is indeed in the word we are displaying)
    // Return false if it is not.

    // See the project writeup for a more detailed description of this function, and also for a discussion
    //      of why this is not necessarily the optimal solution from the point of view of the cheating Hangman:
    //      There are better algorithms (from the point of view of the cheating Hangman), but you are not to implement those. 
    
    // Think carefully about how to implement this with the portions of C++ we have covered so far. 
    // Remember, you are not allowed to use parts of C++ we haven't covered yet, so you can't use 
    // associative arrays, even though one might make this problem easier.     
    bool guessLetter(char guess);
    
    const std::string & getPattern(); // returns the pattern of what user knows at the moment.
    
    size_t possibleWordsRemaining() const; // how many words remain in the word list that fit the desired pattern?
    
private:
    WordList wordsRemaining;
    std::string pattern; // what information does the user currently know about the word?  
    // as an INVARIANT, our goal should be that whenever we are not in the middle of a function
    // (other than playGame()) of this class, every word in the "wordsRemaining" list matches the given pattern.
    
    constexpr static unsigned MAX_FAMILIES = 500; // for purposes of this project, there are never more than this many families
            // within any guess.  You may assume this to be accurate : I am not going to give you a test case where you
            // need more than this many patterns.  
            // This might feel like a constraint when you read this, but I promise it makes the project easier. 
        // This is particularly important for larger word sizes. 

};


#endif
