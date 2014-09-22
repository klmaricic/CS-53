/*Kelsey Maricic
Student number 12354344
9/07/11*/

#include <iostream>
using namespace std;

int main()
{
  //Declare variables
  float weight,length, baroPress,forkLength;
  short stink, forkNmbr;
  const short IDIOTS = 8;
  
  cout<<"Why hello there user!I have a few questions to ask about the 'possem in your possession."<<endl;
  
  cout<<"What is the weight of the of the 'possem?"<<endl;
  cin>>weight;//assign weight to user input value
  
  cout<<"What is the length of the 'possem's tail?"<<endl;
  cin>>length;//assign length to input value
  
  cout<<"What is the barometric pressure of the 'possem?"<<endl;
  cin>>baroPress;//assign barometric pressure to input value
  
  cout<<"What is the stink factor of the carcass?(An integer ranging from 1 to 10)"<<endl;
  cin>>stink;//assign stink level to input value
  
  cout<<endl;
  
  forkLength = (static_cast<float>(stink)/IDIOTS)*(3*length + weight) + 30*(static_cast<float>(stink)/baroPress);//calculate length of pitchfork
  
  forkNmbr = static_cast<short>(forkLength)/10;//calculate which fork to use
  
  //list stats
  cout<<"The stats for your 'possem are as follows:"<<endl;
  cout<<"Weight: "<<weight<<endl;
  cout<<"Length: "<<length<<endl;
  cout<<"Barometric pressure: "<<baroPress<<endl;
  cout<<"Stink level: "<<stink<<endl;
  cout<<endl;
  cout<<"Length of pitchfork: "<<forkLength<<endl;
  cout<<"Pitchfork number: "<<forkNmbr<<endl;
}
