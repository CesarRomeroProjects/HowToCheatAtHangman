#include "catch_amalgamated.hpp"
#include "HangmanGame.hpp"
#include "WordList.hpp"
#include <string>
#include <fstream>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

// WordList test cases are independent from Hangman cases.
// If you pass all of the required test cases for WordList,
//  I will grade your WordList code... even if you are failing one or more cases in Hangman.


TEST_CASE("ConstructionCounts", "[RequiredHangman]")
{
        // To open a file for reading, we do this:
        std::ifstream in("small_words.txt");
        // You may need to adjust the directory depending where you run it.
        // For example, you might need to make it in("/home/mike/small_words.txt")
        // The grading script will have the directories set up correctly!

        HangmanGame hg{in, 4}; // create a game from that word file, using only words of length 4.

        // I expect this will be one you are all able to pass very quickly! :) 
        REQUIRE(hg.possibleWordsRemaining() == 9);
        REQUIRE(hg.getPattern() == "----");
}

TEST_CASE("FromProjectDescription", "[RequiredHangman]")
{
        std::ifstream in("small_words.txt");

        HangmanGame hg{in, 4}; 

        // I expect this will be one you are all able to pass very quickly! :) 
        REQUIRE(hg.possibleWordsRemaining() == 9);
        REQUIRE_FALSE(hg.guessLetter('E'));
        REQUIRE(hg.getPattern() == "----");
        REQUIRE(hg.possibleWordsRemaining() == 3);
}

// I *very strongly* recommend you uncomment this and try this test case at some point,
// because there WILL BE test cases this big on GradeScope, and you need to be reasonably
// efficient.  Don't worry, it is possible!
TEST_CASE("RunABigTestCase", "[JustFYI]")
{
    std::ifstream in("dictionary.txt");

    HangmanGame hg{in, 10};

    // There are better ways to do this in C++, but we haven't discussed them yet.
    char guesses[] = {'x', 'y', 'z', 'q', 'r', 's', 't', 'l', 'j', 'k', 'g', 'd'};
    size_t remai[] = {11952, 10392, 9896, 9699, 3956, 1203, 381, 116, 112, 88, 36, 8};
    constexpr unsigned NUM_GUESSES = 12;


    for(unsigned i=0; i < NUM_GUESSES; i++)
    {
        hg.guessLetter( guesses[i] );
        REQUIRE(hg.possibleWordsRemaining() == remai[i] );
    }
}
                        
} // end namespace

