//PROGRAMMER: KELSEY MARICIC    DATE:9/20/11
//PROGRAM: assgn4.cpp
//PURPOSE:Create a menu that allows the user to either enter a number, cube
//root a number, square a number, or quit

#include<iostream>
using namespace std;

int main()
{
  double squaredNum,cubeRoot1,cubeRoot2,cubeRoot3,cubeRoot4,cubeRoot5,cubeRoot6,cubeRoot7,cubeRoot8,cubeRoot9,cubeRoot10;
  short choice;
  long origNum;
  bool exit = false, userInput = false;
  
 do
 {
   cout<<endl;
   cout<<"Hello there user! Below is a menu of options to choose from."<<endl;
   cout<<"To choose one, enter either '1', '2', '3', or '4'."<<endl<<endl;
   
   cout<<"Menu"<<endl;
   cout<<"---"<<endl;
   cout<<"1. Enter a number"<<endl;
   cout<<"2. Square the number"<<endl;
   cout<<"3. Cube root of the number"<<endl;
   cout<<"4. Quit"<<endl<<endl;
   cin>>choice;  
 
   switch(choice)
   {
     case 1:
       cout<<"Enter a positive integer to be used in calculations."<<endl;
       cin>>origNum;
       
       userInput = true;
       
       while(origNum < 0) //forces user to input a number until it fits the reuirement of being positive
       {
         cout<<"That is not a valid input. Please input a positive integer."<<endl;
         cin>>origNum;
       }
       
       break;
    
     case 2:
       if(!userInput)  //if the user never chose option 1 so that there isn't a number to use in calculations
       {
         cout<<"You haven't entered a number to calculate with."<<endl;
         cout<<"Please choose option 1 from the menu before trying to do calculations."<<endl;
       }
       else
       {  
         squaredNum = origNum*origNum;
         cout<<origNum<<"^2 = "<<squaredNum<<endl<<endl;;
       }
      
       break;
      
     case 3:
       if(!userInput)
       {
         cout<<"You haven't entered a number to calculate with."<<endl;
         cout<<"Please choose option 1 from the menu before trying to do calculations."<<endl;
       }
       else
       { //calculates the cubed root         
         cubeRoot1 = (2*origNum+origNum/(origNum*origNum))/3;
         cubeRoot2 = (2*cubeRoot1+origNum/(cubeRoot1*cubeRoot1))/3;
         cubeRoot3 = (2*cubeRoot2+origNum/(cubeRoot2*cubeRoot2))/3;
         cubeRoot4 = (2*cubeRoot3+origNum/(cubeRoot3*cubeRoot3))/3;
         cubeRoot5 = (2*cubeRoot4+origNum/(cubeRoot4*cubeRoot4))/3;
         cubeRoot6 = (2*cubeRoot5+origNum/(cubeRoot5*cubeRoot5))/3;
         cubeRoot7 = (2*cubeRoot6+origNum/(cubeRoot6*cubeRoot6))/3;
         cubeRoot8 = (2*cubeRoot7+origNum/(cubeRoot7*cubeRoot7))/3;
         cubeRoot9 = (2*cubeRoot8+origNum/(cubeRoot8*cubeRoot8))/3;
         cubeRoot10 = (2*cubeRoot9+origNum/(cubeRoot9*cubeRoot9))/3;
         
         cout<<"The cube root of "<<origNum<<" is "<<cubeRoot10<<endl<<endl;
       }
                                                                               
       break;
       
     case 4:
       exit = true;
       cout<<"Thank you for using this program! Good bye!"<<endl<<endl;
       break;  
                  
     default:
       cout<<"The option you entered is not valid. Please try again."<<endl;
       break;
   }
 }while(!exit);; 
 
 return 0;                       
}
