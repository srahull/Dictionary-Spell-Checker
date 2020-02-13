/*dictionary.cpp
*Created by Rahul Sharma on 1/24/20.
* Tree data structure implementation for inserting and searching words
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const int QuoteMagicNumber = 26; // Return value of quote

// Assigns indices to alphabets and quote and returns it
int dictionary::alphabetToIndex(char alphabet)
{
    if (alphabet >= 'A' && alphabet <= 'Z')
    {
        return alphabet - 'A' ;
    }
    else if (alphabet >= 'a' && alphabet <= 'z')
    {
        return alphabet - 'a';
    }
    else if (alphabet == '\'')
    {
        return QuoteMagicNumber; // QuoteMagicNumber = 26
    }
    
    return -1;
}

// Returns EXISTS if word exists in tree, else
// MISSPELLED
dictionary::ResultType dictionary::find(dictionary::dictentry *dictnode, std::string word){
    
    dictionary::dictentry *currentNode = dictnode;
    
    for (int i = 0; i < word.length(); i++){
        
        int childIndex = alphabetToIndex(word[i]);
        
        // makes a new node if it doesnt exist
        if (currentNode -> next[childIndex] == NULL)
            return dictionary::MISSPELLED;
        //keeps traversing
        currentNode =  currentNode-> next[childIndex];
    }
    // checks to see if word exits
    if(currentNode!=NULL && currentNode->isEndOfWord)
        return dictionary::EXISTS;// returns 4 intention 1
    else
        return dictionary::MISSPELLED;// 1 intention 0
}
// If not present, inserts characters and returns ADDED
dictionary::ResultType dictionary::insert(dictionary::dictentry *dictnode,std:: string characters){
    
    dictionary:: dictentry *currentNode = dictnode;
    
    for (int i = 0; i < characters.length(); i++)
    {
        int childIndex = alphabetToIndex(characters[i]);
        
        // if a path for chars doesnt exist then create one
        if (!currentNode -> next[childIndex])
            currentNode ->next[childIndex] = new dictionary::dictentry();
        
        //traverse
        currentNode = currentNode -> next[childIndex];
    }
    currentNode -> isEndOfWord = true; // set last node isEndOfWord = true
    return dictionary::ADDED;
}




