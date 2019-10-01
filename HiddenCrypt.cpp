/**************************************************************************
** Program Name: HiddenCrypt.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the HiddenCrypt class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "HiddenCrypt.hpp"

#include "Character.hpp"
#include "Enemy.hpp"

using std::cout;
using std::cin;
using std::endl;

HiddenCrypt::HiddenCrypt(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void HiddenCrypt::info() {

  cout << "\n\n";
  cout << "Your party walks into the crypt to see a long room, lined\n";
  cout << "with anicent stone coffins along the walls in alcoves.\n";
  cout << "at the end of the room is an ornate golden chest sealed tight\n";

  cout << "To the north there is a statue of a headless skeleton\n";
  cout << endl;
  cout << "On the east wall there is a statue of a headless skeleton\n";
  cout << endl;
  cout << "On the south wall by the entrance there is a statue of a \n";
  cout << "headless skeleton\n";
  cout << endl;
  cout << "On the west wall there is a statue of a headless skeleton\n";

}

char HiddenCrypt::move(int &hours, std::vector<Character*> &v) {

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
        cout << endl;
        cout << "Your party looks at the chest, then walks back to the\n";
        cout << "center of the crypt";
        cout << endl;
        break;

      case 2:
        cout << endl;
        cout << "Your party looks at the east wall and its coffins,"; 
        cout << "\nthen walk back to the\n";
        cout << "center of the crypt";
        cout << endl;
        break;

      case 3:
        char depart;
        cout << endl;
        cout << "Your party walks back to the entrance of the crypt\n";
        cout << "Do they leave?\n\n";
        cout << "Enter y to leave, enter anything else not to: ";
        cin  >> depart;
        if(depart=='y'||depart=='y') {
          cout << "\nAs the party leaves they watch as ghostly\n";
          cout << "spirits rebuild the barricade on the door!\n";
          cout << endl;
          return 's';
        }
        cout << endl;
        break;

      case 4:
        cout << endl;
        cout << "Your party looks at the west wall and its coffins,"; 
        cout << "\nthen walk back to the\n";
        cout << "center of the crypt";
        cout << endl;
        break;
    }
  }
}

void HiddenCrypt::event(std::vector<Character *> &v) {

  cout << "\n\n";

  // used in solving loop
  bool solving = true;

  // keeps track of which skulls have been placed
  bool nSet = false;
  bool eSet = false;
  bool sSet = false;
  bool wSet = false;

  cout << "Next to the ornate chest are four skulls on pedestals. Each\n";
  cout << "skull has a letter on its forehead. Behind the chest is one\n";
  cout << "of the four headless skeleton statues you saw earlier...\n";

  // 4 skulls in vector
  std::vector<char> skulls;
  skulls.push_back('N');
  skulls.push_back('E');
  skulls.push_back('S');
  skulls.push_back('W');

  // if more than one member in party someone besides the hero
  // picks up the skulls
  if(v.size() > 1) {
    cout << endl;
    cout << v[1]->getName() << " picks up the 4 skulls and reads aloud\n";
    cout << "the letter on each skull's forehead: \n";
    cout << "\"The skulls read N, E, W and S...\"\n";
    cout << v[1]->getName() << " puts the skulls in a rucksack\n";
  }
  // if only hero remains hero picks up the skull
  else {
    cout << endl;
    cout << "Your hero picks up the skulls, the letters read: N,E,S,W\n";
    cout << "Each skull has one of the letters on it.\n";
  }

  // for input validation
  int val = 1;

  while(solving==true) {
  
    // ask user which way they want to go with validation
    char approach;
    cout << "\nWhich statue do you approach?\n";
    cout << "Enter N for the northern statue\n";
    cout << "Enter E for the eastern statue\n";
    cout << "Enter S for the southern statue\n";
    cout << "Enter W for the western statue\n";
    cout << "Choice: ";
    cin  >> approach;
    while(val==1) {
      if(cin.fail() 
        ||(approach!='N'&&approach!='n'
        && approach!='E'&&approach!='e'
        && approach!='S'&&approach!='s'
        && approach!='W'&&approach!='w')) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter an N, E, S, or W: ";
        cin  >> approach;
      }
      else{val=0;}
    }

    // if they go back to the skull statue after placing a skull
    if(nSet==true&&(approach=='n'||approach=='N')) {
      cout << "\nThe northern statue already has a skull on it!\n"; 
    }

    // else if no skull placed yet, ask user which skull they want to try
    else if(nSet==false&&(approach=='n'||approach=='N')) {
      char nStatue;
      cout << "\nWhich skull do you place on the headless statue?\n";
      cout << "Enter an N, E, S or W: ";
      cin  >> nStatue;

      // Keep prompting user for correct input
      while(nStatue!='n'&&nStatue!='N') {
        cout << "\nEither no skull exists with that engraved on it, \n";
        cout << "or that skull does not fit here...\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter an N, E, S or W: ";
        cin  >> nStatue;
      }

      // if chosen properly, set to true
      cout << "\nThe N skull clicks into place!\n";
      nSet = true;
    }

    // if they go back to the skull statue after placing a skull  
    else if(eSet==true&&(approach=='e'||approach=='E')) {
      cout << "\nThe eastern statue already has a skull on it!\n"; 
    }

    // else if no skull placed yet, ask user which skull they want to try
    else if(eSet==false&&(approach=='e'||approach=='E')) {
      char eStatue;
      cout << "\nWhich skull do you place on the headless statue?\n";
      cout << "Enter an N, E, S or W: ";
      cin  >> eStatue;

      // Keep prompting user for correct input
      while(eStatue!='e'&&eStatue!='E') {
        cout << "\nEither no skull exists with that engraved on it, \n";
        cout << "or that skull does not fit here...\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter an N, E, S or W: ";
        cin  >> eStatue;
      }
      // if chosen properly, set to true
      cout << "\nThe E skull clicks into place!\n";
      eSet = true;
    }

    // if they go back to the skull statue after placing a skull
    else if(sSet==true&&(approach=='s'||approach=='S')) {
      cout << "\nThe southern statue already has a skull on it!\n"; 
    }

    // else if no skull placed yet, ask user which skull they want to try
    else if(sSet==false&&(approach=='s'||approach=='S')) {
      char sStatue;
      cout << "\nWhich skull do you place on the headless statue?\n";
      cout << "Enter an N, E, S or W: ";
      cin  >> sStatue;

      // Keep prompting user for correct input
      while(sStatue!='s'&&sStatue!='S') {
        cout << "\nEither no skull exists with that engraved on it, \n";
        cout << "or that skull does not fit here...\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter an N, E, S or W: ";
        cin  >> sStatue;
      }
      // if chosen properly, set to true
      cout << "\nThe s skull clicks into place!\n";
      sSet = true;
    }

    // if they go back to the skull statue after placing a skull
    else if(wSet==true&&(approach=='w'||approach=='W')) {
      cout << "\nThe western statue already has a skull on it!\n"; 
    }

    // else if no skull placed yet, ask user which skull they want to try
    else if(wSet==false&&(approach=='w'||approach=='W')) {
      char wStatue;
      cout << "\nWhich skull do you place on the headless statue?\n";
      cout << "Enter an N, E, S or W: ";
      cin  >> wStatue;

      // Keep prompting user for correct input
      while(wStatue!='w'&&wStatue!='W') {
        cout << "\nEither no skull exists with that engraved on it, \n";
        cout << "or that skull does not fit here...\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter an N, E, S or W: ";
        cin  >> wStatue;
      }
      // if chosen properly, set to true
      cout << "\nThe W skull clicks into place!\n";
      wSet = true;
    }

    // If all skulls are in their proper place
    if(nSet==true&&eSet==true&&sSet==true&&wSet==true) {

      // end loop and clear screen
      solving = false;
      for(int i=0;i<100;i++){cout<<"\n";}

      cout << "The chest at the end of the room clicks loudly!\n";
      cout << "As it clicks, dust puffs off its lid and it opens.\n";
      cout << "Inside the chest is a revive stone and health potions!\n";

      cout << "Who gets the revive stone?\n";
      bool given = false;
      char give;

      // loop through vector and offer revive stone to characters
      // who don't already have one
      for(int i=0; i<v.size(); i++) {
        if(v[i]->hasRstone()==false) {
          cout << "\nWould you like to give " << v[i]->getName()
              << " the revive stone?\n";
          cout << "Enter a y to give, enter anything else not to: ";
          cin  >> give;
          if(give=='y'||give=='Y') {
            v[i]->giveRstone();
            given=true;
            cout << endl;
            cout << v[i]->getName() << " picks up the revive stone!\n";
            i = v.size();
          }
        }
        // if at end of party vector no one took it
        // give revive stone to someone without it
        if(i==v.size()-1 && !given) {
          for(int j=0; j<v.size(); j++) {
            if(v[j]->hasRstone()==false) {
              v[j]->giveRstone();
              cout << endl;
              cout << v[j]->getName() << " picks up the untaken revive stone..";
              cout << endl;
              j = v.size();
            }
          }
        }
      }

      for(int i=0; i<v.size(); i++) {
        cout << endl;
        cout << v[i]->getName() << " picks up a health potion!";
        v[i]->giveHpot(1);
      }
      cout << "\n\n";
    }
  }
}

void HiddenCrypt::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass                                                ^   \n";
 cout<<" 5)Valley                                                  v   \n";
 cout<<" 6)Crypt (You are here!!!!!!!!!!!!)                      * * * \n";
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
