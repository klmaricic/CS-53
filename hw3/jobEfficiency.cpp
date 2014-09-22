//Programmer: KELSEY MARICIC		Date:9/13/11
//Program: jobEfficiency
//Purpose: Tell the worker what to do on the job depending on how motivated they feel

#include<iostream>
using namespace std;

int main()
{
  const double RAIN_LIMIT_C = 1.5, RAIN_LIMIT_A = 0.5; //Rain boundaries for different results for motivation levels a and c
  const int GAS_LOWER_LIM = 5, GAS_UPPER_LIM = 10;     //Gas boundaries for different results
  string name;
  char mtvtn,sprClmr, rain;
  int numKids, numAdults;
  double gas,rainAmount = 0;
  
  cout<<"Hello, this is a program to decide how productive you should be on ";
  cout<<"the job. So, I'll need to ask you a few questions."<<endl;
  
  cout<<"What is your name?"<<endl;
  cin>>name;
  
  cout<<"Did it rain last night?(y/n)"<<endl;
  cin>>rain;
  
  //forces user to eventually  input either 'y' or 'n' by forcing them in a loop until they get it right 
  while((rain != 'y') && (rain != 'n'))
  {
    cout<<"Invalid entry. Did it rain last night? (y/n)"<<endl;
    cin>>rain;
  }
  
  //if it rained, asks how much it rained
  if(rain == 'y')
  {
    cout<<"How many inches did it rain last night?"<<endl;
    cin>>rainAmount;
  }
  
  cout<<"Well then, "<<name<<", what would you say your current level ";
  cout<<"of motivation is? Ranging from a(very motivated) to ";
  cout<<"e(no motivation)"<<endl;
  cin>>mtvtn;
  
  //forces user to give a valid input
  while((mtvtn!='a')&&(mtvtn!='b')&&(mtvtn!='c')&&(mtvtn!='d')&&(mtvtn!='e'))
  {
    cout<<"The level of motivation you put in was not valid. Try again:"<<endl;
    cin>>mtvtn;
  }
  
  if(mtvtn == 'e')
    cout<<"Well, "<<name<<", you should just stay in bed and skip work."<<endl;
  else if(mtvtn == 'd')
  {
    if(rain == 'y')
      cout<<name<<", you should hide in the toolshed."<<endl;
    else
      cout<<name<<", you should hide in the hedges."<<endl;
  }
  else if(mtvtn == 'c')
  {  
    if(rainAmount < RAIN_LIMIT_C)
      cout<<"Well, "<<name<<", you should lean on a rake."<<endl;
    else
      cout<<"Well, "<<name<<", you should lean on a broom inside"<<endl;
  }
  else if(mtvtn == 'b') 
  {
    cout<<"How many kids are present?"<<endl;
    cin>>numKids;
    
    cout<<"How many adults are present?"<<endl;
    cin>>numAdults;
    
    cout<<"Is the Superintendent Chalmers present?(y/n)"<<endl;
    cin>>sprClmr;
    
    //forces user to give a valid input on if the superindendent chalmers was there
    while((sprClmr != 'y') && (sprClmr != 'n'))
    {
      cout<<"Invalid entry.Was the Superintendent Chalmers present?(y/n)"<<endl;
      cin>>sprClmr; 
    }
    
    if((sprClmr == 'y') || (numAdults >= numKids))
      cout<<"Get on hands and knees and scrub floor."<<endl;
    else
      cout<<"Mop the floor."<<endl;
  }
  else  //only option left is mtvtn='a', so goes into that scenario
  {
    cout<<"How many gallons of gas do you have?"<<endl;
    cin>>gas;
    
    if(rainAmount > RAIN_LIMIT_A)
    {
      if(gas < GAS_LOWER_LIM)
        cout<<"You should burn old text books from the 1940's"<<endl;
      else
        cout<<"You should use the gas to clean the bathroom"<<endl;
    }  
    else if((gas > GAS_LOWER_LIM) && (gas < GAS_UPPER_LIM))
      cout<<"You should mow the grass."<<endl;
    else if(gas>GAS_UPPER_LIM)
      cout<<"You should get the tractor and do laps around the school."<<endl;
    else
      cout<<"You should get more gas."<<endl;
  }
  
  cout<<"Thanks you for using this program, "<<name<<"! Goodbye!"<<endl;
} 
