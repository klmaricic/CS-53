//PROGRAMMER: Kelsey Maricic DATE: 11/4/11
//PROGRAM: assgn8fnctns.cpp
//PURPOSE: Simulates a madlib

#include "assgn8.h"
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<ctime>
#include<cstdlib>
using namespace std;

void greetings()
{
  cout<<endl<<"Hello. This program creates a madlib."<<endl<<endl;
  return;
}


void printStory()
{
  ifstream fin("story.dat");
  char lineOfStory[ARRAY_SIZE];

  do
  {
    fin.getline(lineOfStory, ARRAY_SIZE-1);
    cout<<lineOfStory<<endl;
  } while(!fin.eof());

  fin.close();
  
  return;
}
     

void replaceWords()
{
  ifstream fin("story.dat");
  
  char tempBegin[ARRAY_SIZE], wordType[ARRAY_SIZE], replacement[ARRAY_SIZE];

  cout<<endl<<"The story blanks will now be filled in"<<endl<<endl;   
  
  do
  {
    fin.getline(tempBegin, ARRAY_SIZE, '*');
    fin.getline(wordType, ARRAY_SIZE, '*');
    
    
    if(strcmp(wordType, "nouns") == 0)
      randWord("nouns.dat", replacement);
    else if(strcmp(wordType, "nounp") == 0)
      randWord("nounp.dat", replacement);
    else if(strcmp(wordType, "verbp") == 0)
      randWord("verbp.dat", replacement);
    else if(strcmp(wordType, "adj") == 0)
      randWord("adjective.dat", replacement);
    else if(strcmp(wordType, "verb") == 0)
      randWord("verb.dat", replacement);
        
    cout<<tempBegin;
    cout.flush();
    if(!fin.eof())
    {
      cout<<replacement;
      cout.flush();
    }
    
  } while(!fin.eof());
  
  fin.close(); 
}


void randWord(const char file[], char word[]) 
{
  int lineNum, numOfLines;
  ifstream finReplaceWord(file);
  
  finReplaceWord>>numOfLines;

  lineNum = rand()%(numOfLines -1);

  for(int i = 0; i < lineNum; i++)
    finReplaceWord>>word;
    
  finReplaceWord.close(); 
}

void goodBye()
{
  cout<<endl<<endl<<"Thank you for using this program. Good bye!"<<endl;
}
