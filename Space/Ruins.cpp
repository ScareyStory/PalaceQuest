/**************************************************************************
** Program Name: Ruins.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Ruins class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "Ruins.hpp"
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

Ruins::Ruins(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Ruins::info() {

  cout << "\n\n";
  cout << "The party arrives in a town to the south of a large lake.\n";
  cout << "\nAcross the lake to the north is the palace\n";
  cout << "\nTo the east and west there is nothing interesting...\n";
  cout << "Shadows seem to dart between ruined homes, but there is no\n";
  cout << "life in sight.\n";
  
}

char Ruins::move(int &hours, std::vector<Character*> &v) {

  cout << endl;
  cout << "Knowing the town holds nothing for the party, they decide to\n";
  cout << "move on";
  cout << endl;

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
    char go;

    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    switch(d) {
      case 1:
        cout << endl;
        cout << "To the north lies a lake that goes out to the palace\n\n";
        cout << "Enter a y to go to the lake, anything else not to: ";
        cin  >> go;
        if(go=='y'||go=='Y') {
          cout << "\n\nThe party heads to the lake!\n";
          hours--;
          return 'n';
          break;
        }
        cout << "\n\nThe party stays in the ruins\n";
        cout << endl;
        break;

      case 2:
        cout << endl;
        cout << "To the east lies nothing but dead hills\n";
        cout << "The party knows not to go that way...\n";
        cout << endl;
        break;

      case 3:
        cout << endl;
        cout << "To the south lies the forest\n\n";
        cout << "Enter y to go to the forest, anything else not to: ";
        cin  >> go;
        if(go=='y'||go=='Y') {
          cout << "\n\nThe party heads back to the forest\n";
          hours--;
          return 's';
          break;
        }
        cout << "\n\nThe party stays in the ruins\n";
        cout << endl;
        break;

      case 4:
        cout << endl;
        cout << "To the west lies nothing but dead hills\n";
        cout << "The party knows not to go that way...\n";
        cout << endl;
        break;
    }
  }
}

void Ruins::event(std::vector<Character *> &v) {}

void Ruins::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass                                                ^   \n";
 cout<<" 5)Valley                                                  v   \n";
 cout<<" 6)Crypt                                                 * * * \n";
 cout<<" 7)Forest                                                * 9 * \n";
 cout<<" 8)Ruins (You are here!!!!!!!!!!!!)                      * * * \n";
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
