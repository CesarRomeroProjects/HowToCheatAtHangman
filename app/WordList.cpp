#include <string>
#include "WordList.hpp"


// Note:  in the definition, we do not specify that initialCapacity has a default value a second time.
// The word 'explicit' is also not repeated here. 
WordList::WordList(size_t initialCapacity)
: m_words{new std::string[ initialCapacity ]}, m_capacity{ initialCapacity }, m_numWords{ 0 }
{

}
    
    
// The destructor is important.  Memory management of the word list is 1.5 points out of 9 on this project
// and it is mostly (but not entirely) within this function.
// Think very carefully about what you do here. 
    
WordList::~WordList()
{
    // TODO implement me.
    delete[] m_words;
}    
    
void WordList::addWord(const std::string & s)
{
    // TODO implement me.
    if (m_numWords >= m_capacity) {
        size_t newCapacity{m_capacity * 2};

        std::string *newWords = new std::string[newCapacity];

        for (size_t i{0}; i < m_numWords; i++) {
            newWords[i] = m_words[i];
        }

        delete[] m_words;
        m_capacity = newCapacity;
        m_words = newWords;
    }
    m_words[m_numWords] = s;
    m_numWords++;
}
    
bool WordList::removeWord(size_t index)
{
    // TODO implement me.
    if (index >= 0 && index < m_numWords) {
        for (size_t i{index}; i < m_numWords - 1; i++) {
            m_words[i] = m_words[i + 1];
        }
        m_numWords--;
        return true;
    }
    return false;
}

    
std::string & WordList::wordAt(size_t index)
{
    // TODO implement me.
    if (index >= 0 && index < m_numWords)
    {
        return m_words[index];
    } else {
        return m_words[0];
    }
}

const std::string & WordList::wordAt(size_t index) const
{
    // TODO implement me.
    if (index >= 0 && index < m_numWords) {
        return m_words[index];
    } else {
        return m_words[0];
    }
}


size_t WordList::getCapacity() const
{
    return m_capacity;
}


size_t WordList::getSize() const
{
    return m_numWords;
}
    

    
    