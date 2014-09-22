//PROGRAMMER: KELSEY MARICIC   DATE: 10/11/12
//PROGRAM: assgn6.cpp
//PURPOSE: Takes a value from the user and performs the requested calculations

#ifndef ASSGN6_H
#define ASSGN6_H

const int NUM_ITERATIONS_ROOT = 20;//num of iterations the root calculation does
const int NUM_ITERATIONS_EXP = 10;//num of iterations the exp calculation does

//Def: Prints out a greeting message
//Pre: None
//Post: outputs a message to the screen
void greetings();

//Def: displays the menu and gets the chosen option from the user
//Pre: None
//Post: Returns the input from the user of their menu option selection
char displayMenuAndGetOption();

//Def: Makes sure the user input is valid(is a num from  1-5)
//Pre: None
//Post: returns a menu option that is valid(is a num from 1-5)
char validate(char option);

//Def:Makes sure the user input is valid(is a positive number)
//Pre: None
//Post: returns a positive number specified by the user
double validate(double mainNum);

//Def: Makes sure the user input is valid(is a positive int)
//Pre: None
//Post: return a positive int specified by the user
int validate(int expNum);
 
//Def: Prompts the user to enter a positive number and then returns that number
//Pre: None
//Post: returns a number
double getMainNum();

//Def:Prompts the user to enter a positive int and then returns that number
//Pre: None
//Post: returns a number
int getExponentNum();

//Def: calculates mainNum^exponentNum and returns that value
//Pre: mainNum and exponentNum must be positive
//Post: return the value of mainNum^exponentNum
double calculateExponentN(const double mainNum, const int exponentNum);

//Def:prints out the answer to the appropriate equation
//Pre: mainNum and exponentNum must be +, option must be from 1-5
//Post: outputs the answer to the appropriate equation to the screen
void displayAnswer(const double mainNum, const int exponentNum,
                   const double answer, const char option);
                                                        
//Def: Calculates the user defined root of the number
//Pre: mainNum and exponentNum are positive
//Post: returns the exponentNum root of mainNum
double calculateRootN(const double mainNum, const int exponentNum);

//Def: calulcates e^mainNum
//Pre: mainNum is positive
//Post: returns e^mainNum
double calculateExponentMainNum(const double mainNum);

//Def: Calculates the factorial of num(num! = 1*2*3*..*num)
//Pre: num is positive
//Post: returns the factorial of num
int factorial(const int num);

//Def: prints out a goodbye message
//Pre: None
//Post: outputs a goodbye message to the screen
void goodbye();

#endif
