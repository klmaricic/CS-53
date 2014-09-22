//PROGRAMMER: KELSEY MARICIC  DATE: 10/02/11
//PROGRAM: assgn5
//PURPOSE: Give the user options regarding a row of lockers, then process
//the input and output acccordingly

#include<iostream>
using namespace std;

struct Locker
{
  short numLocker, numBooks;
  string lastName;
  float money;
};

int main()
{
  const short MAX_LOCKER_NUM = 201, MIN_LOCKER_NUM = 101;
  const short NUM_LOCKERS = MAX_LOCKER_NUM - MIN_LOCKER_NUM + 1;
  short lockerIndex, lockerNumberTemp, booksTotal = 0, numOccupied = 0; 
  float moneyTotal = 0;
  char option;
  bool quit = false;
  Locker lockerArray[NUM_LOCKERS];
  
  do
  {
    cout<<endl<<endl<<endl;
    cout<<"Hello! This program contains information on lockers 101-201."<<endl;
    cout<<" Choose an option from the menu"<<endl<<endl;
    cout<<"\t MENU"<<endl;
    cout<<"\t ----"<<endl;
    cout<<"1. Add a locker"<<endl;
    cout<<"2. Print contents of a locker"<<endl;
    cout<<"3. Output all locker contents"<<endl;
    cout<<"4. Delete a locker"<<endl;
    cout<<"5. Quit"<<endl<<endl;
    
    //states how many lockers are currently occupied
    if(numOccupied == 1)
      cout<<"There is "<<numOccupied<<" locker occupied"<<endl;
    else  
      cout<<"There are "<<numOccupied<<" lockers occupied"<<endl;
    
    //states how many books on average are in a locker
    if(numOccupied != 0)//if there is at least one occupied locker
      cout<<"There is an average of "<<booksTotal/numOccupied<<" books"<<
            " per locker"<<endl;
    else
      cout<<"There is an average of 0 books per locker."<<endl;
              
    cin>>option;
    cout<<endl;
    
    switch(option)
    {
      //makes chosen locker occupied, assigns values to all of its variables
      case'1':
      case 'a':
      case 'A':
        cout<<"What is the locker number?(101 to 201)"<<endl;
        cin>>lockerNumberTemp;
    
        //makes sure the locker number is within the correct range
        if(lockerNumberTemp > 201 || lockerNumberTemp < 101)
        {
          cout<<"That is not a valid locker number"<<endl;
          break;
        }
        
        //calculates the index of where the locker should go in the array
        lockerIndex = MAX_LOCKER_NUM - lockerNumberTemp;
        
        if(lockerArray[lockerIndex].lastName != "")//if the locker is occupied
        {
          cout<<"That locker is already taken."<<endl;
          break;
        }
        
        numOccupied++;  //adds 1 to the total number of lockers occupied
        
        //assigns the locker its number
        lockerArray[lockerIndex].numLocker = lockerNumberTemp;
 
        cout<<"What is the student's last name?"<<endl;
        cin>>lockerArray[lockerIndex].lastName;

        cout<<"How many books are going to be stored in locker "<<
		lockerNumberTemp<<"?"<<endl;
        cin>>lockerArray[lockerIndex].numBooks;

        //adds the number of newly added books to the total sum
        booksTotal += lockerArray[lockerIndex].numBooks;

        cout<<"How much money is in locker "<<lockerNumberTemp<<"?"<<endl;
        cin>>lockerArray[lockerIndex].money;
        
        //adds the amount of newly added money to the total sum
        moneyTotal += lockerArray[lockerIndex].money;
        
        break;

      //outputs info of chosen locker
      case '2':
      case 'p':
      case 'P':
        cout<<"What is the number of the locker?"<<endl;
        cin>>lockerNumberTemp;
     
        //makes sure the input is within the correct range
        if(lockerNumberTemp > 201 || lockerNumberTemp < 101)
        {
          cout<<"That is not a valid locker number"<<endl;
          break;
        }
        
        //finds the index where the locker will be stored in the array                                    
        lockerIndex = MAX_LOCKER_NUM - lockerNumberTemp;

        if(lockerArray[lockerIndex].lastName == "")//if empty
        {
          cout<<"That locker is not occupied"<<endl;
          break;
        }

        cout<<"Locker "<<lockerNumberTemp<<":"<<endl;
        cout<<"Is owned by "<<lockerArray[lockerIndex].lastName<<"."<<endl;
        cout<<"Contains "<<lockerArray[lockerIndex].numBooks;
        if(lockerArray[lockerIndex].numBooks == 1)
          cout<<" book."<<endl;
        else
          cout<<" books."<<endl;
        
        //makes the output go to two decimal places for the money value
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);    
        cout<<"Contains $"<<lockerArray[lockerIndex].money<<"."<<endl;
        
        break;

      //lists contents of all occupied lockers
      case '3':
      case 'o':
      case 'O':
        cout<<"Lockers:"<<endl;
        
        //outputs the info on every occupied locker
        //The lockers are stored from largest number to smallest
        //so the lockers are read out backwards
        for(int i = MIN_LOCKER_NUM - 1; i >= 0; i--)
        {  
          if(lockerArray[i].lastName != "")//if occupied, output info
          { 
            cout<<lockerArray[i].numLocker<<"\t"<<lockerArray[i].lastName<<"\t"
                <<lockerArray[i].numBooks;
                if(lockerArray[i].numBooks == 1)
                  cout<< " book"<<"\t\t";
                else
                  cout<<" books"<<"\t\t";
               
            //outputs money value to 2 decimal places    
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.precision(2);    
            cout<<"$"<<lockerArray[i].money<<endl;
          }
        }

        break;

      //empties chosen locker
      case '4':
      case 'd':
      case 'D':
        cout<<"What locker do you want to be emptied?"<<endl;
        cin>>lockerNumberTemp;

        lockerIndex = MAX_LOCKER_NUM - lockerNumberTemp;
        if(lockerArray[lockerIndex].lastName == "")
        {
          cout<<"That locker is unoccupied."<<endl;
          break; 
        } 
        
        //removes locker from total number of occupied lockers
        numOccupied--;
        
        //subtracts the amount of books and money erased from the total
        moneyTotal -= lockerArray[lockerIndex].money;
        booksTotal -= lockerArray[lockerIndex].numBooks;
        
        //clears out all variables tied to that locker 
        lockerArray[lockerIndex].lastName = "";
        lockerArray[lockerIndex].numBooks = 0;
        lockerArray[lockerIndex].money = 0;

        cout<<"Locker "<<lockerNumberTemp<<" is now empty."<<endl;

        break;

      //ends program
      case '5':
      case 'q':
      case 'Q':
        quit = true;
        cout<<"Thank you for using this program! Good bye!"<<endl;
        break;

      default:
        cout<<"The option you put in was not valid. Please try again"<<endl;
    }
    
    //if there is over $150 total, Willy steals all of the money
    if(moneyTotal > 150)
    {
      for(int i = MIN_LOCKER_NUM - 1; i >= 0; i--)
      {
        lockerArray[i].money = 0;
      }
      
      moneyTotal = 0;
      cout<<endl<<"Willy took all of the money!"<<endl;
               
    }
      
  }while(!quit);

  return 0;
}

