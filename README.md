# Project 2: How To Cheat at Hangman

# Overview
In this project, you will create a program that plays Hangman and cheats in a specific way. The goal is to maximize the number of possible words remaining after each user guess. The cheating algorithm involves considering all words of the given length initially and strategically eliminating words based on user guesses.

# Hangman Game
The game involves a computer thinking of a word, and the player making guesses. Unlike a typical Hangman game, the computer cheats by initially considering all words of a given length. After each guess, it strategically narrows down the possible words to maximize its chances of winning.

# Cheating Algorithm 
The cheating algorithm involves maintaining word lists and selecting the list with the maximum number of consistent words after each user guess. The provided HangmanGame class includes a private member variable for the list of words consistent with the information the user has.

# Algorithm Steps:
1. Create an array of WordLists.
2. For each word in the remaining possibilities, check if it belongs to the same family as any non-empty WordList in the array.
3. If the word matches a family, add it to that list.
4. If it doesn't match any family, add it to the first empty WordList.
5. Replace the current instance's word list with the largest family.

# Restrictions
- Do not use libraries that were not covered in the lecture.
- Do not add any additional #include directives without written permission from the professor.
- You may add "helper functions" (additional private member functions), but do not remove or change declared functions.
