#include "catch_amalgamated.hpp"
#include "WordList.hpp"
#include <string>

// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.
// However, be aware that if ANY test marked "Required" fails, 
// your score for the portion will be zero, regardless of other considerations.


namespace{

// WordList test cases are independent from Hangman cases.
// If you pass all of the required test cases for WordList, I will grade your WordList code... even if you are failing one or more cases in Hangman.
// If you really really can't figure out WordList and want to write the Hangman portion, you *may* attempt it with std::vector (you will need to #include <vector>),
// however, I believe this will make it harder for you than learning how to write the WordList.


/*
This LOOKS LIKE a lot of test cases!  
Remember you DO NOT need to pass every case the first time you build.
build and run tests for the starting code, and look through the case(s) that fail.
Read the description in the test files.

Decide which one you think will be the easiest to achieve:  what is the smallest amount of programming you can do to pass one more test case?  Write that code and find out.  If you now pass it, repeat -- what is the smallest amount of programming you can do to pass one more test case (without causing any previously-passing test cases to now fail).

Believe it or not, this will make programming a lot easier.  In future projects, you might want to write a lot of different test cases yourself at the beginning, based on reading the skeleton code and the project requirements, and then try the above approach.  You might find yourself turning what feels like a very large and intimidating programming assignment into a series of small, very manageable mini-projects. 

*/

TEST_CASE("CreateAWordListDefault", "[RequiredWordList]")
{
        WordList w;
        REQUIRE( w.getCapacity() == 10 );
        REQUIRE( w.getSize() == 0 );
}

TEST_CASE("CreateAWordListNonDefault", "[RequiredWordList]")
{
        WordList w{15};
        REQUIRE( w.getCapacity() == 15 );
        REQUIRE( w.getSize() == 0 );
}


TEST_CASE("AddJustOneWord", "[RequiredWordList]")
{
        WordList w;
        REQUIRE( w.getCapacity() == 10 );
        REQUIRE( w.getSize() == 0 );
        w.addWord( "foo" );
        REQUIRE( w.getCapacity() == 10 );
        REQUIRE( w.getSize() == 1 );
}

TEST_CASE("AddFiveWordsToCapacityFive", "[RequiredWordList]")
{
        // Was your professor hungry when he wrote this test case?
        // Also notice:  this function just cares that this is std::string types,
        // even if they wouldn't (or shouldn't) be added for Hangman.
        WordList w{5};
        REQUIRE( w.getCapacity() == 5 );
        REQUIRE( w.getSize() == 0 );
        w.addWord( "refried beans" );
        w.addWord( "sour cream" );
        w.addWord( "guacamole" );
        w.addWord( "salsa" );
        w.addWord( "cheese" );
        REQUIRE( w.getCapacity() == 5 );
        REQUIRE( w.getSize() == 5 );
}

TEST_CASE("AddSevenWordsPastCapacityFive", "[RequiredWordList]")
{
        // Was your professor hungry when he wrote this test case?
        // Also notice:  this function just cares that this is std::string types,
        // even if they wouldn't (or shouldn't) be added for Hangman.
        // Both in this class and out of it, you should not test WordList *only* for how it
        // interacts with the Hangman game. 
        WordList w{5};
        REQUIRE( w.getCapacity() == 5 );
        REQUIRE( w.getSize() == 0 );
        w.addWord( "refried beans" );
        w.addWord( "sour cream" );
        w.addWord( "guacamole" );
        w.addWord( "salsa" );
        w.addWord( "cheese" );
        REQUIRE( w.getCapacity() == 5 );
        REQUIRE( w.getSize() == 5 );
        w.addWord( "green onions" );
        w.addWord( "olives" );
        REQUIRE( w.getCapacity() == 10 );
        REQUIRE( w.getSize() == 7 );
}

bool wordAppears(const WordList & w, const std::string & word)
{
        for(size_t i{0}; i < w.getSize(); i++)
        {
                if( w.wordAt(i) == word)
                        return true;
        }
        return false;
}


TEST_CASE("WordAtTestOne", "[RequiredWordList]")
{
        WordList w;
        w.addWord("refried beans");
        REQUIRE(w.wordAt(0) == "refried beans");
        w.addWord("sour cream");
        REQUIRE(w.wordAt(1) == "sour cream");
}

TEST_CASE("WordAtTestTwoAfterARemoval", "[RequiredWordList]")
{
        WordList w;
        w.addWord("refried beans");
        w.addWord("sour cream");
        w.addWord("guacamole");
        REQUIRE(w.wordAt(1) == "sour cream");
        REQUIRE(w.removeWord(1));
        REQUIRE(w.getSize() == 2);
        REQUIRE( wordAppears(w, "refried beans"));
        REQUIRE( wordAppears(w, "guacamole"));
}


TEST_CASE("WordAtTestThreeAfterARemoval", "[RequiredWordList]")
{
        WordList w{5};
        w.addWord( "refried beans" );
        w.addWord( "sour cream" );
        w.addWord( "guacamole" );
        w.addWord( "salsa" );
        w.addWord( "cheese" );
        REQUIRE( wordAppears(w, "refried beans"));
        REQUIRE( wordAppears(w, "sour cream"));
        REQUIRE( wordAppears(w, "guacamole"));
        REQUIRE( wordAppears(w, "salsa"));
        REQUIRE( wordAppears(w, "cheese"));

        REQUIRE( w.removeWord(1)); // this is too bad, I like sour cream.
        REQUIRE( wordAppears(w, "refried beans"));
        REQUIRE( wordAppears(w, "guacamole"));
        REQUIRE( wordAppears(w, "salsa"));
        REQUIRE( wordAppears(w, "cheese"));
}

                        
} // end namespace

