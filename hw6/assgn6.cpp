//PROGRAMMER: KELSEY MARICIC   DATE: 10/11/12
//PROGRAM: assgn6.cpp
//PURPOSE: Takes a value from the user and performs the requested calculations

#include<iostream>
using namespace std;
#include "assgn6.h"

int main()
{
  char option;
  double mainNum = -1, answer;
  int exponentNum;
  bool quit = false;
  
  greetings();
  
  do
  { 
    cout<<endl; 
    option = displayMenuAndGetOption();
    option = validate(option);
    
    switch(option)
    {
      //Takes the input value of the main number
      case '1':
        mainNum = getMainNum();
        mainNum = validate(mainNum);
        break;
      
      //calculates mainNum^exponentNum 
      case '2':
        if(mainNum == -1)//if option 1 had not been previously chosen
        {
          cout<<"You need to first select option 1"<<endl;
          break;
        }
        
        exponentNum = getExponentNum();
        exponentNum = validate(exponentNum);
        answer = calculateExponentN(mainNum, exponentNum);
        displayAnswer(mainNum, exponentNum, answer, option); 
        break;
      
      //calculates the exponentNum root of mainNum     
      case '3':
        if(mainNum == -1)//if option 1 had not been previously chosen
        {
          cout<<"You need to first select option 1"<<endl;
          break;
        }
                                             
        exponentNum = getExponentNum();
        exponentNum = validate(exponentNum);
        answer = calculateRootN(mainNum, exponentNum);
        displayAnswer(mainNum, exponentNum, answer, option);
        break;
      
      //calculates e^mainNum  
      case '4':
        if(mainNum == -1)//if option 1 had not been previously chosen
        {
          cout<<"You need to first select option 1"<<endl;
          break;
        }
                                  
        answer = calculateExponentMainNum(mainNum);
        displayAnswer(mainNum, exponentNum, answer, option);
        break;
      
      //quits the program  
      default:
        quit = true;
        
    }
        
  }while(!quit);
  
  goodbye();
  return 0;
}
