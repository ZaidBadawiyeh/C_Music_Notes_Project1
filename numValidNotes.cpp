// CSCI1300 Fall 2022
// Author: Zaid Badawiyeh
// Recitation 204 Enora Rice
// Project 1-Problem 3-numValidNotes

/**
* Algorithm: determine and add up successful notes in a string 
* Accept isValidNote and create a new function for numValidNotes with a string as an input
* imput a string and tests it for perameters of SPN
* Paramters: isValidNote (bool), numValidNote (int)
* Returns: Successfuly outputs an integer for the number of correct notes in a string.
*/


#include <iostream>
#include <string>
#include <cassert>

using namespace std;
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

int numValidNotes(string tune) //creating a function for numValidNotes
{
    int x = 0; //set int x
   
   
    int tuneLength = tune.length(); //set a variable for the length of the tune
   
   
    for(int p=0; p < tuneLength; p++)  //going through every postion to make a substring 
    { 
        string note = tune.substr(p,2);//create a substring with two positions
        
        if (isValidNote(note)) //call isValidNote
      
        {
            x=x+1;//adding one to the int for every correct note.
        }
 
 
    }
    return x;//return total numbers of correct notes
}

int main()
{
assert(numValidNotes("I find comp sci interesting"));//test case 1, should return 0
assert(numValidNotes("A5B6C7D8E9F1"));//test case 2, should return 6
}
