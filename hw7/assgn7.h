//PROGRAMMER: KELSEY MARICIC    DATE: 10/19/11
//PROGRAM: assgn7.h
//PURPOSE: Create a simulation to find the percent of time Willie finds a
          //sandwich, falls out windows, and how many bruises he has
          
#ifndef ASSGN7_H
#define ASSGN7_H

const int MAX_RUNS = 100000, MAX_STEPS = 42;
const int Y_SQUARES = 17, X_SQUARES = 17;
const char WINDOW = 'F';
const char  WALL = 'B', JANITOR = 'J', SANDWICH = 'S';


struct Stats
{
  int foundSandwichNum;
  int fellNum;
  int passedOutNum;
  int numBruises;
};

//runs 1 simulation of Willie randomly walking around the school looking for
//the sandwich
//Pre: none
//Post:Willie is moved, returns value correlating with the results of the 
      //search, adds the number of bruises caused by hitting walls
char runSimulation();


//Checks to see if the spot Willie plans to move to is free or is take up by a 
//window or wall
//Pre: y and x must be within the range of the array
//Post: returns an int indicating wether the spot Willie plans to move into is 
      //free or is occupied by a wall or window
int checkSquare(const int y, const int x, 
                const char schoolArray[Y_SQUARES][X_SQUARES]);


//Greets the user
//Pre: none
//Post: outputs a greeting message to the screen
void greetings();


//Sets up the border of the school arrray and cleans out the garbage
//Pre: Y_SQUARES and X_SQUARES must be positive ints
//Post: The bordering values of the 2d array are all assigned chars indicating 
       //either windows that are spread out every 4 spaces or walls and all
      //spaces have the value of '_'
void setArray(char schoolArray[Y_SQUARES][X_SQUARES]);

//places the lunch in a random spot
//Pre: Y_SQUARES and X_SQUARES must be positive ints
//Post: assigns one of the spot in the array the value that represents lunch
void placeLunch(char schoolArray[Y_SQUARES][X_SQUARES]);

//Prints out the different stats resulting from the simulation
//Pre: None
//Post: Outputs the stats of the simulation to the screen
void giveReport(int foundSandwichNum, int fellNum,
             int passedOutNum, int numBruises);

//Prints out the goodbye message
//Pre: None
//Post: Outputs the goodbye message to the screeb
void goodbye();

#endif
