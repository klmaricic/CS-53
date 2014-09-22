//PROGRAMMER: KELSEY MARICIC    DATE: 10/19/11
//PROGRAM: assgn7.cpp
//PURPOSE: Create a simulation to find the percent of time Willie finds a sandwich, falls out windows, and how many bruises he has

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "assgn7.h"


#include<iostream>
using namespace std;

int main()
{
  Stats willieSimulation;
  char result;
      
  srand(time(NULL));
  greetings();
  
  willieSimulation.foundSandwichNum = 0;
  willieSimulation.fellNum = 0;
  willieSimulation.passedOutNum = 0;
  willieSimulation.numBruises = 0;
              
  for(int i = 0; i < MAX_RUNS; i++)
  { 
    result = runSimulation();
                      
    if(result == WINDOW)
      willieSimulation.fellNum++;
    else if(result == SANDWICH)
      willieSimulation.foundSandwichNum++;
    else if(result == WALL)
      willieSimulation.numBruises++;
  }
                                            
  giveReport(willieSimulation.foundSandwichNum, willieSimulation.fellNum,
             willieSimulation.passedOutNum, willieSimulation.numBruises);
                                              
  goodbye();
                                                
  return 0;
} 
                                                  
