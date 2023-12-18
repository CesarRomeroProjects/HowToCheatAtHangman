#include "HangmanGame.hpp"
#include <iostream>

int main()
{
    std::ifstream in("small_words.txt");    // change this if you want a different word file.

    HangmanGame hg{in, 4};  // change this if you want a different word size from that file.
    // Note that "small_words.txt," as provided, has only four letter words (and not *those* four letter words)

    hg.playGame();
    
    return 0;
}

