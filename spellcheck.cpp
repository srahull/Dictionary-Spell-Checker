/*spellcheck.cpp
 *Created by Rahul Sharma on 1/24/20.
 * This file drives the dictionary population and spellchecking
 */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "dictionary.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char **arg) {
    
    
    // outputs invalid arguments if more or less than 3 arguments have been entered
    if(argc != 3){
        cout<<"invalid arguments"<<endl;
        return -1;
    }
    
    std::ifstream fileToCheck(arg[1]);          //reads in "Austen-Pride-and-Prejudice.txt"
    std::ifstream dictionaryBuilder(arg[2]);    //reads in "aspell_list_en.txt" //
    
    // checks if both files can open
    if (!fileToCheck.is_open() || !dictionaryBuilder.is_open()){
        cout<< "unable to open"<<endl;
        return -1;
        //fstream.close();
    }
    
    
    const char *separators = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~"; // delimiters
    
    dictionary::dictentry *currentNode = new dictionary::dictentry();
    dictionary *words = new dictionary();
    
    std::string str;
    
    // Extracts characters from fileToCheck and stores them into str until end of file
    while (std::getline(dictionaryBuilder, str))
    {
        
        char line_c[str.size() + 1];    // creating line_c.size > str.size
        strcpy(line_c, str.c_str());    // copies str into Line_c
        
        char *token = (char*)strtok(line_c, separators); // parses each line buffer
        while (token != NULL)
        {
            words->insert(currentNode, token);
            //cout<<token<<endl;
            token = strtok(NULL, separators); // get the next token from the line_c buffer
        }
    }
    // Extracts characters from fileToCheck and stores them into str until end of file
    while (std::getline(fileToCheck, str))
    {
        char line_c[str.size() + 1];    // creating line_c.size > str.size
        strcpy(line_c, str.c_str());    // copies str into Line_c
        
        char *token = (char*)strtok(line_c, separators); // parses each line buffer
        while (token != NULL)
        {
            // checks to see if return of find() == MISSPELLED
            if (words->find(currentNode, token) == dictionary::MISSPELLED)
                cout<<token<<endl;
            token = strtok(NULL, separators);  // get the next token from the line_c buffer
        }
    }
    
    
    return 0;
};

