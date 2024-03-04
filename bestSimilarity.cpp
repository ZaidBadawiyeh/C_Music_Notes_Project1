// CSCI1300 Fall 2022
// Author: Zaid Badawiyeh
// Recitation 204 Enora Rice
// Project 1-Problem 5- best similarity


#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool doublesEqual(double a, double b, const double epsilon = 1e-2)

double tuneSimilarity (string tune1, string tune2)//create a function for tuneSimilarity with double as the variable
{
    if(tune1.length() != tune2.length()) // if the tune lengths of both of the functions 
    {
        return 0; //if tune lengths dont equal each other then return false ie 0
    }
    double tuneNumber = (tune1.length() / 2); //we need this step for the math to be able to divide mc by the proper amount.
   
    double dm = 0; //set variable for when it doesnt match the note or the pitch
   
    double matchingNote = 0;//set variable for when it doesnt match the note
   
    double matchingNoteMatchingPitch = 0;//set variable for when it matches the note and the pitch
    for(int i = 0; i < tune1.length(); i = i + 2)//set a variable for traversing the string and set it to traverse it by 2
    {
        if(tune1[i] == tune2[i] && tune1[i+1] == tune2[i+1]) //if tune matches the note and the pitch add to mc and mcmp
        {
            matchingNote++;
            matchingNoteMatchingPitch++;
        }
        else if((tune1[i] == tune2[i]) && tune1[i+1] != tune2[i+1])//if note matches but the pitch doesnt add one to matching note
        {
            matchingNote++;
        }
         else if((tune1[i] != tune2[i]) && tune1[i+1] != tune2[i+1])//if the note and the pitch doesn't match then add one to doesnt match note doesnt match pitch
        {
            dm++;
        }
    }
    double similarity = (matchingNote / tuneNumber) + matchingNoteMatchingPitch - dm; //run the math equation in the gethub to find the similarity score
    return similarity;//return with the similarity score
}

double bestSimilarity(string inputT, string targetT) //create function with a double output and two string inputs
{
    double goal = -800;
    
    
    if(inputT.length() < targetT.length())
    {
        return 0;
    }
    for (int j = 0; j <= inputT.length() - targetT.length(); j+=2)
    {
        
        string inputS = inputT.substr(j, targetT.length()) ;
      
        
        if(tuneSimilarity(inputS, targetT) > goal) 
        {
            goal = tuneSimilarity(inputS,targetT);
        }
    }
    return goal;
        
}

int main()
{
    assert(bestSimilarity("G5B2C3","G5B3C5") )); //test case 1
    assert(bestSimilarity("G4F5C3","G5B3C5") )); //test case 2
}