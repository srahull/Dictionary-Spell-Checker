/*dictionary.h
 *Created by Rahul Sharma on 1/24/20.
 *
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>


class dictionary{
public:
    static const int Nchars = 27; /* a-z + ' */
    class dictentry{
    public:
        bool isEndOfWord;
        
        dictentry *next[Nchars];
    };
    
    typedef enum {
        CORRECT,    // returns 0
        MISSPELLED, // returns 1
        BADCHARS,   // returns 2
        ADDED,      // returns 3
        EXISTS,     // returns 4
    } ResultType;
    
    dictionary::ResultType find(dictionary::dictentry *dictnode, std::string word);
    
    dictionary::ResultType insert( dictionary::dictentry *dictnode, std::string characters);
    
    int alphabetToIndex(char alphabet);
};

#endif
