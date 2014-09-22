//PROGRAMMER: KELSEY MARICIC   DATE: 10/11/12
//PROGRAM: assgn6Fnctns.cpp
//PURPOSE: Takes a value from the user and performs the requested calculations

#include "assgn6.h"
#include<iostream>
using namespace std;

void greetings()
{
  cout<<endl<<"Hello! This program takes a value given by you and performs the"<<
        " requested calculations."<<endl<<endl;
      
  return;
}

char displayMenuAndGetOption()
{
  char option;
  
  cout<<"Please pick one of the following options"<<endl<<endl;
  cout<<"MENU"<<endl;
  cout<<"----"<<endl;
  cout<<"1. Enter the main number(x)"<<endl;
  cout<<"2. Calculate x^n"<<endl;
  cout<<"3. Calculate the n root of x"<<endl;
  cout<<"4. Calculate e^x"<<endl;
  cout<<"5. Exit"<<endl<<endl;;
  
  cin>>option;
  cout<<endl<<endl;
  
  return option;
}

char validate(char option)
{
  //while not a valid option
  while(option != '1' && option != '2' && option != '3' &&
        option != '4' && option != '5')
    {
      cout<<"That is an invalid input. Please choose an option from 1-5"<<endl;
      option = displayMenuAndGetOption();
    }
    
  return option;
}

double getMainNum()
{
  double num;
  cout<<"Please enter a positive number"<<endl;
  cin>>num;
  cout<<endl<<endl;
        
  return num;
}          

double validate(double mainNum)
{
  while(mainNum <= 0)
  {
    cout<<"That is an invalid number."<<endl<<endl;
    mainNum = getMainNum();
  }
  
  return mainNum;
}

int validate(int expNum)
{
  while(expNum <= 0)
  {
    cout<<"That is an invalid number. Please enter a positive integer."<<endl;
    expNum = getExponentNum();
  }
            
  return expNum;             
}

int getExponentNum()
{
  int num;
  
  cout<<"Please enter a positive integer."<<endl;
  cin>>num;
  cout<<endl<<endl;
  
  return num; 
}

double calculateExponentN(const double mainNum, const int exponentNum)
{
  double answer = mainNum;
  
  for(int i = 1; i < exponentNum; i++)
  {
    answer *= mainNum;
  }
  
  return answer;  
}

void displayAnswer(const double mainNum, const int exponentNum,
                   const double answer, const char option)
{
  if(option == '2')
    cout<<mainNum<<"^"<<exponentNum<<" = "<<answer<<endl;
  else if(option == '3')
    cout<<"Root "<<exponentNum<<" of "<<mainNum<<" = "<<answer<<endl;
  else  //option 4
    cout<<"e^"<<mainNum<<" = "<<answer<<endl;
    
  return; 
}

double calculateRootN(const double mainNum, const int exponentNum)
{
  double answer = mainNum;
  for(int i = 1; i <= NUM_ITERATIONS_ROOT; i++)
  {
    answer = ((exponentNum - 1)*answer + 
             mainNum/calculateExponentN(answer, exponentNum - 1))/exponentNum;
  }
  
  return answer;
}

int factorialNum(const int num)
{
  int answer = 1;
  
  for(int i = 1; i <= num; i++)
  {
    answer = answer * i;
  }
            
  return answer;
}
              

double calculateExponentMainNum(const double mainNum)
{
  double answer = 1;
  
  for(int i = 1; i <= NUM_ITERATIONS_EXP; i++)
  {
    answer += (calculateExponentN(mainNum, i) / factorialNum(i));
  }
  
  return answer;   
}

void goodbye()
{
  cout<<"Thank you for using this program. Good bye!"<<endl;
}  




            

