//PROGRAMMER: KELSEY MARICIC    DATE: 10/19/11
//PROGRAM: assgn7Fnctns.cpp
//PURPOSE: Create a simulation to find the percent of time Willie finds a sandwich, falls out windows, and how many bruises he has

#include "assgn7.h"
#include<iostream>
#include <ctime>    
#include <cstdlib>
using namespace std;

char runSimulation()
{
  bool quit = false;
  int steps = 0, proceed;
  int xWillie = X_SQUARES/2;
  int yWillie = Y_SQUARES/2;
  char endResult;
  
  char schoolArray[Y_SQUARES][X_SQUARES];
  
  setArray(schoolArray);
  placeLunch(schoolArray);
          
  do
  {
    int direction = 1 + rand()%4;
                    
    if(direction == 1)
      proceed = checkSquare(yWillie-1,xWillie, schoolArray);
    else if(direction == 2)
      proceed = checkSquare(yWillie,xWillie+1, schoolArray);
    else if(direction == 3)
      proceed = checkSquare(yWillie++,xWillie, schoolArray);
    else 
      proceed = checkSquare(yWillie,xWillie-1, schoolArray);
                                                                  
                                                                  
    if(proceed == 3)//free space
    {
      steps++;
      
      schoolArray[yWillie][xWillie] = '_';
                                                                              
      if(direction == 1)
        yWillie--;
      else if(direction == 2)
        xWillie++;
      else if(direction == 3)
        yWillie++;
      else
        xWillie--;
        
      schoolArray[yWillie][xWillie] = JANITOR;  
    }
    else if(proceed == 2)//window in spot
    {
      quit = true;
      endResult = WINDOW;
    }
    else if(proceed == 3)
    {
      quit = true;
      endResult = SANDWICH;
    }  
    else
    {
      steps++;
      endResult = WALL;  
    } 

  }while(!quit && steps < MAX_STEPS);
                                                                                                                                                                                                                          
  return endResult;
}  

                                                                                                                                                                                                                            
int checkSquare(const int y, const int x,
                const char schoolArray[Y_SQUARES][X_SQUARES])
{
  if(schoolArray[y][x] == WALL)
    return 1;    
  else if(schoolArray[y][x] == WINDOW)
    return 2;
  else if(schoolArray[y][x] == WALL)
    return 3;
  else
    return 4;
}
                                                                                                                                                                                                                                                       
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
void greetings()
{
  cout<<"Hello! This program simulates Willie's behaviour while he is drunk."<<endl;
  return;
}
                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                           
void setArray(char schoolArray[Y_SQUARES][X_SQUARES])
{ 
  int numWallSquares = 0;
  for(int i = 0; i < X_SQUARES; i++)
  {
    if(numWallSquares == 3)
    {
      schoolArray[0][i] = WINDOW;
      numWallSquares = 0;
      cout<<WINDOW;
    }
    else
    {
      schoolArray[0][i] = WALL;
      numWallSquares++;
      cout<<WALL;
    }
  } 
                                                                                                                                                                                                                                                                                                                  
  schoolArray[0][X_SQUARES-1] = WALL;                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                    
  for(int j = 0; j < Y_SQUARES - 1; j++)
  {
    if(numWallSquares == 3)
    {
      schoolArray[j][X_SQUARES-1] = WINDOW;
      numWallSquares = 0;
      cout<<WINDOW<<endl;
    }
    else
    {
      schoolArray[j][X_SQUARES-1] = WALL;
      numWallSquares++;
      cout<<WALL<<endl;
    }
  }
                                                                                                                                                                                                                                                                                                                                                                           
  schoolArray[Y_SQUARES-1][X_SQUARES-1] = WALL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  for(int i = X_SQUARES-1; i > 0; i--)
  {
    if(numWallSquares == 3)
    {
      schoolArray[Y_SQUARES-1][i] = WINDOW;
      numWallSquares = 0;
      cout<<WINDOW;
    }
    else
    {
      schoolArray[Y_SQUARES-1][i] = WALL;
      numWallSquares++;
      cout<<WALL;
    }
  }
                                                                                                                                                                                                                                                                                                                                                                                                                                   
  schoolArray[Y_SQUARES-1][0] = WALL;
                                                                                                                                                                                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                                                                                                                                                     
  for(int j = Y_SQUARES - 1; j > 0; j--)
  {
    if(numWallSquares == 3)
    {
      schoolArray[j][0] = WINDOW;
      numWallSquares = 0;
      cout<<WINDOW<<endl;
    }
    else
    {
      schoolArray[j][0] = WALL;
      numWallSquares++;
      cout<<WALL<<endl;
    }
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    schoolArray[0][0] = WALL;
    
    
    
    
  for(int i = 1; i < Y_SQUARES-1; i++)
  {
    for(int j = 1; j < X_SQUARES - 1; j++)
    {
      schoolArray[i][j] = '_';
    }
  }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  return;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
void placeLunch(char schoolArray[Y_SQUARES][X_SQUARES])
{
  srand(time(0));
  int y = 1 + rand()%(Y_SQUARES-2);
  int x = 1 + rand()%(X_SQUARES-2);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
  schoolArray[y][x] = SANDWICH;
  return;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
void giveReport(int foundSandwichNum, int fellNum,int passedOutNum, 
                int numBruises)
{
  cout<<"For "<<MAX_RUNS<<" runs of the simulator I got the following results:"
      <<endl;
  cout<<(static_cast<float>(fellNum)/MAX_RUNS)*100<<"% Willie fell out the window."<<endl;
  cout<<(static_cast<float>(passedOutNum)/MAX_RUNS)*100<<"% Willie passed out on the floor."<<endl;
  cout<<(static_cast<float>(foundSandwichNum)/MAX_RUNS)*100<<"% Willie found the lunch"<<endl;
  cout<<"Willie sustained "<<numBruises<<" bruises. (Avg "
       <<numBruises/MAX_RUNS<<" per run)"<<endl;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  return;
}

void goodbye()
{
  cout<<"Thank you for using this program. Goodbye!"<<endl;
  return;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
