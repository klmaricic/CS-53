//PROGRAMMER: Kelsey Maricic  DATE: 11/4/11
//PROGRAM: assgn8.h
//PURPOSE: Simulates a madlib

#ifndef ASSGN8_H
#define ASSGN8_H


const int ARRAY_SIZE = 300;

//Greets the user
//Pre: none
//Post: Outputs a greeting message to the screen
void greetings();

//prints out the original story
//pre: none
//post:outputs the story to the screen
void printStory();

//chooses a random word from the appropriate file
//pre: file must consist of an existing file name
//post: changes the replacement variable to a random word from the chosen file
void randWord(const char file[], char word[]);

//replaces the "blank" spaces with the corresponding random word
//pre:none
//post: outputs the changed story to the screen
void replaceWords();

//prints out a good bye message
//pre: none
//post: outputs a good bye message to the screen 
void goodBye();

#endif
