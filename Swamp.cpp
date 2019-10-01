/**************************************************************************
** Program Name: Swamp.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Swamp class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "Swamp.hpp"
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

Swamp::Swamp(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Swamp::info() {

  cout << "Your party walks into a swamp, sounds of various animals can\n";
  cout << "be heard all around.\n"; 
  cout << "\nTo the north the swamp stretches on for miles\n";
  cout << "\nTo the east is the start of a steep mountain pass\n";
  cout << "\nTo the south the swamp wraps round the mountains and into the\n";
  cout << "foothills.\n"; 
  cout << "\nThe prison is directly west.\n\n"; 
  
}

char Swamp::move(int &hours, std::vector<Character *> &v) {

  char give;
  cout << "In the muck of the swamp an old staff can be seen buried\n";
  cout << "halfway up its length.\n";
  cout << "\nA monk or mage without a staff could take it...\n\n";

  if((v[0]->getType()==3 || v[0]->getType()==4) 
    && v[0]->hasWeapon()==false && staff > 0) {

    cout << "Do you give your hero the staff?\n";
    cout << "Enter a y to give, enter anything else to not: ";
    cin  >> give;

    if(give=='y'||give=='Y') {
      v[0]->giveWeapon();
    }
    else {
      cout << "\nYour hero foregoes the staff\n";
    }
  }
  else if((v.size() > 1)&&((v[1]->getType()==3 || v[1]->getType()==4) 
    && v[1]->hasWeapon()==false && staff > 0)) {

    cout << "Do you give "<<v[1]->getName()<<" the staff?\n";
    cout << "Enter a y to give, enter anything else to not: ";
    cin  >> give;

    if(give=='y'||give=='Y') {
      v[1]->giveWeapon();
    }
    else {
      cout << endl;
      cout << v[1]->getName() << " foregoes the staff\n";
    }
  }
  //If party size is 3 and a mage or monk is unarmed still
  else if((v.size() > 2)&&((v[2]->getType()==3 || v[2]->getType()==4) 
    && v[2]->hasWeapon()==false && staff > 0)) {

    cout << "Do you give "<<v[2]->getName()<<" the staff?\n";
    cout << "Enter a y to give, enter anything else to not: ";
    cin  >> give;

    if(give=='y'||give=='Y') {
      v[2]->giveWeapon();
    }
    else {
      cout << endl;
      cout << v[2]->getName() << " foregoes the staff\n";
    }
  }
  else {cout << "\n\nYour party leaves the staff in the muck\n\n";}

  char dir;
  bool moving = true;
  int val = 1;

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

    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    switch(d) {
    
      case 1:

        cout << "To the north the swamp stretches endlessly\n";
        cout << "Your party knows it is not worth going that way\n";

        break;

      case 2:

        char pass;
        cout << endl;
        cout << "To the east lies the mountains, a pass cuts up and\n";
        cout << "through them. Your map shows that this pass saves time\n";
        cout << "but it looks treacherous, the foothills are safer, but\n";
        cout << "take longer to get through...\n\n";
        cout << "Does your party head east up the mountain pass?\n";

        cout << "Enter y to take the pass, enter anything else to not: ";
        cin  >> pass;

        if(pass=='y'||pass=='Y') {hours--;return 'e';}

        else {
          cout << "\n\nYour party chooses to not take the pass\n\n";
        }
        break;

      case 3:

        char f;
        cout << endl;
        cout << "To the south is the opening to the foothills that run\n";
        cout << "south of the mountains. They are safer than the pass\n";
        cout << "through the mountains, but take longer, do you take\n";
        cout << "the foothills?\n";
        cout << endl;
        cout << "Enter y to take the foothills,"; 
        cout << " enter anything else to not: ";
        cin  >> f;

        if(f=='y'||f=='Y') {hours--;return 's';}

        else {cout << "\nYour party chooses not to take the foothills\n";}

        break;

      case 4:
        
        char p;
        cout << endl;
        cout << "To the west is the prison, do you re-enter it?\n";
        
        cout << "Enter y to enter, enter anything else to not: ";
        cin  >> p;

        if(p=='y'||p=='Y') {hours--;return 's';}

        else {cout << "\nYour party chooses not to return to the prison\n";}

        break;
    }
  }
}

// FIXME: MAKE EVENT THE STAFF PICKUP!!! right now it can be found again
//no event
void Swamp::event(std::vector<Character *> &v) {}

void Swamp::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp (You are here!!!!!!!!!!!!)                      * * * \n";
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
