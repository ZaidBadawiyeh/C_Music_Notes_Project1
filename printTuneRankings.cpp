// CSCI1300 Fall 2022
// Author: Zaid Badawiyeh
// Recitation 204 Enora Rice
// Project 1-Problem 6-printTuneRanking

/**
* Algorithm: The function will accept three input tunes and one target tune, prints the input tunes in order from best to worst match 
* Accept bestSimilarity for 3 different tunes, comparing each to the target tune
* Assign similarity score to three variables for each tune, based on the target using bestSimilarity
* Else/if statements will procede or print based on highest value until it finds the correct perameters
* Paramters: isValidNote (bool), bestSimilarity (double), t1,t2,t3 (double)
* Returns: Runs program and lists them from greatest to least similarity score
*/


#include <iostream>
#include <iomanip>
#include <string>

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


void printTuneRankings(string tune1, string tune2, string tune3, string targetTune)//create a void function with 4 string inputs
{
    double t1 = bestSimilarity(tune1, targetTune);//define variable for similarity score of the first tune using bestSimilarity
    double t2 = bestSimilarity(tune2, targetTune);//define variable for similarity score of the second tune using bestSimilarity
    double t3 = bestSimilarity(tune3, targetTune);//define variable for similarity score of the third tune using bestSimilarity
   
   if((t1 >= t2 && t2 >= t3))// lines 10-37 are creating if and if else statement for each possible combination of ranking
   {
    cout << "1) Tune 1, 2) Tune 2, 3) Tune 3 ";//print statement
   }
   else if(t1 >= t3 && t3 >= t2)
   {
    cout<< "1) Tune 1, 2) Tune 3, 3) Tune 2";//print statement
   }
   else if(t2 >= t1 && t1 >= t3)
   {
    cout<<"1) Tune 2, 2) Tune 1, 3) Tune 3";//print statement
   }
   else if(t2 >= t3 && t3 >= t1)
   {
    cout<<"1) Tune 2, 2) Tune 3, 3) Tune 1";//print statement
   }
    else if(t3 >= t1 && t1 >= t2)
    {
        cout << "1) Tune 3, 2) Tune 1, 3) Tune 2";//print statement
    }
    else if(t3 >= t2 && t2 >= t1)
    {
        cout << "1) Tune 3, 2) Tune 2, 3) Tune 1";//print statement
    }
    else
    {
        cout << "1) Tune 3, 2) Tune 1, 3) Tune 2";//print statement
    }
}

int Main()
{
   printTuneRankings("G7", "G4", "B7", "G7"); //test case 1, will output "1) Tune 1, 2) Tune 2, 3) Tune 3 "
   printTuneRankings("B7", "G7", "B6", "G7"); //test case 1, will output "1) Tune 2, 2) Tune 1, 3) Tune 3"
}