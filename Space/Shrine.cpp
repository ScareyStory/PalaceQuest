/**************************************************************************
** Program Name: Shrine.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Shrine class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "Shrine.hpp"
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

Shrine::Shrine(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Shrine::info() {

  cout << "\n\n";
  cout << "The shrine is peaceful and beautiful, it was a spot where the\n";
  cout << "Forest dwellers, ages past, would come and worship the forest\n";
  
}

char Shrine::move(int &hours, std::vector<Character*> &v) {

  cout << "\n";
  cout << "Feeling rejuvenated your party decides to leave the shrine\n";

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
        char f;
        cout << "To the north lies the forest clearing from ealier\n";
        cout << "Does the party continue their journey?\n\n";
        cout << "Enter a y to continue, anything else not to: ";
        cin  >> f;
        if(f=='y'||f=='Y') {
          cout << "\n\nThe party continues on!\n";
          hours--;
          return 'n';
          break;
        }
        cout << "\n\nThe party stays at the shrine\n";
        cout << endl;
        break;

      case 2:
        cout << endl;
        cout << "To the east lies nothing but ever denser forest\n";
        cout << "The party knows not to go that way...\n";
        cout << endl;
        break;

      case 3:
        cout << endl;
        cout << "To the south lies nothing but ever denser forest\n";
        cout << "The party knows not to go that way...\n";
        cout << endl;
        break;

      case 4:
        cout << endl;
        cout << "To the west lies nothing but ever denser forest\n";
        cout << "The party knows not to go that way...\n";
        cout << endl;
        break;
    }
  }
}

void Shrine::event(std::vector<Character *> &v) {

  cout << "\n\n";
  cout << "The base of the shrine has a revive stone and health potions!\n";

  cout << "Who gets the revive stone?\n";

  // holds user choice
  char give;

  // checks if stone has been given
  bool given = false;

  // Loop through team vector and ask user who they want to give
  // the revive stone to
  for(int i=0; i<v.size(); i++) {
    if(v[i]->hasRstone()==false) {
      cout << "\nWould you like to give " << v[i]->getName()
           << " the revive stone?";
      cout << "\nEnter a y to give, enter anything else to not: ";
      cin  >> give;
      if(give=='y'||give=='Y') {
        v[i]->giveRstone();
        cout << v[i]->getName() << " picks up the revive stone!\n";
        i = v.size();
        given = true;
      }
    }

    // if at end of vector give the stone to the first occurring
    // team member without an rstone
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
  // Give everyone in the party a health potion
  for(int i=0; i<v.size(); i++) {
    cout << endl;
    cout << v[i]->getName() << " picks up a health potion!";
    v[i]->giveHpot(1);
  }
  cout << "\n\n";
}

void Shrine::map() {
  for(int i=0;i<100;i++){cout<<"\n";}
  cout<<"YOU ARE AT THE SHRINE (THE \"?\" SPACE)\n";
  cout<<"                                                                \n";
  cout<<" 1)Grotto                                                * * *  \n";
  cout<<" 2)Prison                                                * ! *  \n";
  cout<<" 3)Swamp                                                 * * *  \n";
  cout<<" 4)Mt. Pass                                                ^    \n";
  cout<<" 5)Valley                                                  v    \n";
  cout<<" 6)Crypt                                                 * * *  \n";
  cout<<" 7)Forest                                                * 9 *  \n";
  cout<<" 8)Ruins                                                 * * *  \n";
  cout<<" 9)Lake                                                    ^    \n";
  cout<<" !)Palace                                                  v    \n";
  cout<<"                                               * * *     * * *  \n";
  cout<<"                                               * 6 *     * 8 *  \n";
  cout<<"                                               * * *     * * *  \n";
  cout<<"                                                 ^         ^    \n";
  cout<<"                                                 v         v    \n";
  cout<<"       * * *     * * * <-- * * * <-- * * * <-- * * * <-- * * *  \n";
  cout<<"       * 1 * --> * 2 *     * 3 *     * 4 *     * 5 *     * 7 *  \n";
  cout<<"       * * *     * * * --> * * * --> * * * --> * * * --> * * *  \n";
  cout<<"                                 |                ^        ^    \n";
  cout<<"                                 v                |        v    \n";
  cout<<"                                 ******************      * * *  \n";
  cout<<"                                 *    Foothills   *      * ? *  \n";
  cout<<"                                 ******************      * * *  \n";
  cout<<"                                         |^                     \n";
  cout<<"                                         v|                     \n";
  cout<<"                                      *******                   \n";
  cout<<"                                      * Hut *                   \n";
  cout<<"                                      *******                   \n";
}
