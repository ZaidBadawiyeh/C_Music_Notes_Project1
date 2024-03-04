
// CSCI1300 Fall 2022
// Author: Zaid Badawiyeh
// Recitation 204 Enora Rice
// Project 1-Problem 2-isValidTune

/**
* Algorithm: Output a 1 or a 0 depending on whether or not a tune is valid
* Accept isValidTune,isValidTune and pass it to the funtion isValidNote
* Function makes subtrings from the input string and tests them for parameters given. must be A-G all capitalized and 1-9.
* True/False statements will let function return 0 or 1 if the input is incorrect/correct for substrings
* Paramters: isValidNote (bool), isValidTune (bool)
* Returns: 0 or 1 based on true or false
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

bool isValidTune(string tune) //creating isValidTune function
{
    if (tune.length() % 2 != 0) //make sure that the length of the tune is an even number
    {
        return 0;
    }
    for(int i=0; i <= tune.length() - 2; i = i+2) //checking capitalization and bounds of each letter in string
    {
        string note = tune.substr(i,2);//creating a substring consisting of two characters
        bool validity = isValidNote(note); //calling function to check if note is correct
        if (validity == false) //if the note is not valid return false
        {
            return 0;
        }
    }
    return 1; //return true
}

int main()
{
assert(isValidTune("hello!")); //test case 1, should return 0
assert(isValidTune("G7H1Y7"));//test case 2, should return 0
assert(isValidTune(("B2G7E4A3")); //test case 3, should return 1
}