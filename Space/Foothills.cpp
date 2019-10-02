/**************************************************************************
** Program Name: Foothills.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Foothills class.
**************************************************************************/
#include <iostream>
#include <vector>

#include "Foothills.hpp"
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

Foothills::Foothills(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Foothills::info() {

  cout << "\n\n";
  cout << "Your party arrives in the foothills.\n\n";
  cout << "To the north, the south side of the mountains loom high\n";
  cout << "\nTo the east the foothills lead to path to a valley\n";
  cout << "\nTo the south lies an old hut\n";
  cout << "\nTo the west lies the path back to the swamps...\n";
  cout << endl; 
  
}

char Foothills::move(int &hours, std::vector<Character *> &v) {

  int val = 1;
  char dir;
  bool moving = true;
  while(moving==true) {
    char map;
    cout << "\nWould you like to see a map of the realm before moving?\n";
    cout << "Enter a y to see the map, anything else to not: ";
    cin  >> map; 
    if(map=='y' || map=='Y') {
      for(int i=0;i<100;i++){cout<<"\n";}
      this->map();
    }    

    cout << endl;
    cout << "Which way does your hero move?\n";
    cout << "Enter n for north\n";
    cout << "Enter e for east\n";
    cout << "Enter s for south\n";
    cout << "Enter w for west\n";
    cout << "\nDirection: ";

    val = 1;
    cin >> dir;
    while(val==1) {

      if(cin.fail()
        ||(dir!='n' && dir!='N'
        && dir!='e' && dir!='E'
        && dir!='s' && dir!='S'
        && dir!='w' && dir!='W')) {

        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a n, e, s, or w only: ";
        cin  >> dir;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   

    for(int i=0;i<100;i++){cout<<"\n";}
    int d;
    bool opened = false;
    bool rog = false;

    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    switch(d) {
    
      case 1:

        cout << "To the north the mountains loom over the foothills\n";
        cout << "Your party knows it is not scalable that way...\n";

        break;

      case 2:

        char path;
        cout << endl;
        cout << "To the east the foothills lead to path into what looks\n";
        cout << "to be valley thick with gloom and fog...\n\n";

        cout << "Enter y to take the path, enter anything else to not: ";
        cin  >> path;

        if(path=='y'||path=='Y') {hours-=2;return 'e';}

        else {
          cout << "\n\nYour party chooses to not take the path\n\n";
        }
        break;

      case 3:

        char h;
        cout << endl;
        cout << "To the south a hut lies next to a slow running river...\n";
        cout << "It's front door is locked tight, a rogue could be able\n";
        cout << "to open such a lock...\n\n";

        for(int i=0;i<v.size();i++) {
          if(v[i]->getType()==2) {
            cout << v[i]->getName() << " opens the lock!\n";
            opened = true;
            rog = true;
          }
        }
        if(rog==false){cout << "Your party does not have a rogue...\n";}

        if(opened==true) {
          cout << "Note: entering the hut will not pass time\n\n\n";
          cout << "Enter y to enter the hut, enter anything else to not: ";
          cin  >> h;

          if(h=='y'||h=='Y') {return 's';}

          else {cout << "\nYour party chooses not to enter the hut\n";}
        }
        else {cout << "Your party walks away from the locked door...\n\n";}
        break;

      case 4:
        
        char s;
        cout << endl;
        cout << "To the west is the swamp, do you re-enter it?\n";
        
        cout << "Enter y to re-enter, enter anything else to not: ";
        cin  >> s;

        if(s=='y'||s=='Y') {hours--;return 'w';}

        else {cout << "\nYour party chooses not to return to the swamp\n";}

        break;
    }
  }
}

//no event
void Foothills::event(std::vector<Character *> &v) {}

void Foothills::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"YOU ARE IN THE FOOTHILLS\n";
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass                                                ^   \n";
 cout<<" 5)Valley                                                  v   \n";
 cout<<" 6)Crypt                                                 * * * \n";
 cout<<" 7)Forest                                                * 9 * \n";
 cout<<" 8)Ruins                                                 * * * \n";
 cout<<" 9)Lake                                                    ^   \n";
 cout<<" !)Palace                                                  v   \n";
 cout<<"                                               * * *     * * * \n";
 cout<<"                                               * 6 *     * 8 * \n";
 cout<<"                                               * * *     * * * \n";
 cout<<"                                                 ^         ^   \n";
 cout<<"                                                 v         v   \n";
 cout<<"       * * *     * * * <-- * * * <-- * * * <-- * * * <-- * * * \n";
 cout<<"       * 1 * --> * 2 *     * 3 *     * 4 *     * 5 *     * 7 * \n";
 cout<<"       * * *     * * * --> * * * --> * * * --> * * * --> * * * \n";
 cout<<"                             |                   ^         ^   \n";
 cout<<"                             v                   |         v   \n";
 cout<<"                             *********************       * * * \n";
 cout<<"                             *     Foothills     *       * ? * \n";
 cout<<"                             *********************       * * * \n";
 cout<<"                                      |^                       \n";
 cout<<"                                      v|                       \n";
 cout<<"                                   *********                   \n";
 cout<<"                                   *  Hut  *                   \n";
 cout<<"                                   *********                   \n";
}
