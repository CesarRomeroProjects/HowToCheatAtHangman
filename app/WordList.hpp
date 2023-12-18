#ifndef __45C_HANGMAN_WORD_LIST_HPP
#define __45C_HANGMAN_WORD_LIST_HPP


class WordList
{
public:
    explicit WordList(size_t initialCapacity = 10); 
    // This means that, by default, a WordList has a capacity of 10 at the beginning.
    // Don't worry (for now) what the word "explicit" means in the constructor (or its absence in WordList.cpp)
    // You can think of it as "if you are going to make a WordList, you need to create one."
    // I will explain that later. 
    
    
    
    // Later, we will see assignment and copy operators.  Those would be a good idea here,
    // but we have not yet covered them.  Therefore, you are not expected to do them for this
    // project. 
    
    
    // The destructor is important.  Memory management of the word list is 1.5 points out of 9 on this project
    // and it is mostly (but not entirely) within this function.
    // Think very carefully about what you do here. 
    
    ~WordList();
    
    // adds the given string (which is assumed to be a word) to the end of the given WordList.     
    void addWord(const std::string & s);
    
    bool removeWord(size_t index); 
    // remove the given index'd word from the list, return true, unless that index is out of bounds, in which case, return false.
    // If index is in bounds:
        // When this function returns, your wordList is EXACTLY one size smaller, with capacity unchanged (even if size is now less than half the capacity).
        // After your function returns, m_words[0 .. getSize() - 1] should contain the words that are in the list, which are exactly the words that were
        // in the list previously, minus the one that was removed. 
    
    std::string & wordAt(size_t index); // NOTE:  this has UNDEFINED BEHAVIOR for this project if index is out of bounds.
    // I promise that in all of my test cases, I will call this with 0 <= index < number-of-words-in-list (which is hopefully the result of getSize())
    // However, the right way to deal with this if index is out of bounds is not something we have covered in ICS 45C yet.

    // Okay, what's this next function doing here, you might ask.  It looks a lot like the last one!

    // suppose you have a const WordList -- perhaps a parameter to a function.
    // How would you ensure that you could still call wordAt?  
    // The previous function can technically allow a user to change a word.  
    // This works the same way, but does not allow whoever is looking up the word to change anything.
    const std::string & wordAt(size_t index) const;

    
    
    // Please note the difference between the following two.
    
    // This is the CAPACITY of the WordList: how many std::string can m_words hold without needing to increase capacity again?
    // Please see the test case in the relevant file if the difference is not clear to you.
    size_t getCapacity() const;
    
    // This is the SIZE of the word list.  From the point of view of the user, they might never call any function 
    // related to capacity -- or even know it exists!  As far as they know, WordList is an array that has exactly 
    // this many spots, and they are all taken by a word.  
    // So, upon construction, WordList has a size of zero but a capacity of ten (unless a different initial capacity is specified)
    size_t getSize() const; 
    

private:
    std::string * m_words;
    size_t m_capacity; 
    size_t m_numWords;    
};

#endif

