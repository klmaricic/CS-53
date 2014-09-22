//PROGRAMMER: Kelsey Maricic   DATE: 11/4/11
//PROGRAM: assgn8.cpp
//PURPOSE: Simulates a madlib

#include "assgn8.h"
#include<ctime>
#include<cstdlib>

int main()
{ 
  srand(time(NULL));
  
  greetings();
  
  printStory();
  
  replaceWords();
  
  goodBye();

  return 0;
}
