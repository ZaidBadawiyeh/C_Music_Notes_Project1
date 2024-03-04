
// CSCI1300 Fall 2022
// Author: Zaid Badawiyeh
// Recitation 204 Enora Rice
// Project 1-Problem 1-isValidNote

/**
* Algorithm: Make sure that a correct input is given, A-G, 1-9
* Craete isValidNote 
* Function takes a string that may or may not be a note and tests it for parameters set (A-G and 1-9)
* True/False statements will determine if the function continues if the input returns 1
* Paramters: isValidNote (bool)
* Returns: 0 or 1 based on whether or not the string is a correct note
*/


#include <iostream>
#include <string>
#include <cassert>
using namespace std;
{}
    bool isValidnote(string note)// set up a new function for isValidNote with the output as a bool
    {
       
        if(note[0]<= 64 || note[0]>= 72)// return false if the letter is not a capital from A to G
        {
            return 0;
        }
       
        if(note[1]<48 || note[1] > 58)// return false if the number is not 1 to 9
        {
            return 0;
      
        }  
        else//otherwise return as true
       
        {
            return 1;
        }
        return 0;
    }

    int main()
    {
assert(isValidnote(B6)); //test 1, should return 1
assert(isValidnote(H7)); //test 2, should return 0
assert(isValidnote(G12)); //test 3, should return 0
    }