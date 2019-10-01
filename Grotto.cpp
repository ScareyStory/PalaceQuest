/**************************************************************************
** Program Name: Grotto.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Grotto class.
**************************************************************************/
#include <iostream>
#include <vector>
#include "Grotto.hpp"
#include "Character.hpp"

using std::cout;
using std::cin;
using std::endl;

Grotto::Grotto(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Grotto::info() {

  cout << "\nThe Grotto smells of ancient filth, your hero's eyes water.\n";
  
}
  
char Grotto::move(int &hours, std::vector<Character*> &v) {

  char dir;
  bool moving = true;

  //Loop until user decides direction
  while(moving==true) {
    cout << endl;
    cout << "Which way does your hero move?\n";
    cout << "Enter n for north\n";
    cout << "Enter e for east\n";
    cout << "Enter s for south\n";
    cout << "Enter w for west\n";
    cout << "\nDirection: ";

    int val = 1;
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
    
    int d;
    
    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    cout << endl;

    switch(d) {

      // user chose to go to wall with window
      case 1:
        char look;
        cout << "\nYou approach the wall with the window\n";
        cout << "Would you like to look out through it?\n";
        cout << "Enter y for yes or anything else for no: ";
        cin  >> look;
        if(look=='y' || look=='Y') {
          for(int i=0;i<100;i++){cout<<"\n";}
          cout <<"\nYour hero looks out the window to behold"<< 
                 " a desolate scene.\n";
          cout <<"The sky above rumbles angrily as clouds of black and\n";
          cout <<"red swirl like angry titans. Below them the plains of\n";
          cout <<"Arden Duhl stretch endlessly northwards, their once\n";
          cout <<"lush grasses now replaced by dust and beige shrubbery.\n";
          cout <<"Your hero sighs and walks back to the center of the cell";
          cout << endl;
        } else {
          cout <<"\nYour hero walks back to the center of the room.\n";
        }
        break;
      
      // user chose to approach cell door
      case 2:
        cout <<"Your hero approaches the cell door and stares out at the\n";
        cout <<"hall beyond. Out from the darkness an old man begins to\n";
        cout <<"walk up. Your hero rubs their eyes, not knowing what to \n";
        cout <<"make of this sight. The hermit walks up, raises his head\n";
        cout <<"and the hero sees his eyes to both be cloudy white with\n";
        cout <<"blindness. The hermit chuckles softly and mutters\n\n";
        cout <<"\"There they are right on time, right on time indeed\"\n";
        cout <<"Your hero, puzzled, wonders to themself how it is they\n";
        cout <<"came to be in this cell and who or what is respnsible.\n";
        cout <<"The Hermit clears his throat, \"You there! Hehehe\"\n";
        cout <<"\"Do you remember your purpose? Did you ever know it?\"\n";
        cout <<"\"Ah ah no need to answer, the Palace will hold all\n";
        cout <<"the answers you seek. And here is a map I believe will\n";
        cout <<"come in handy! Hehehe\"\n";
        cout <<"\"Oh! And you've only the day to make it there! Ahem\"\n\n";
        cout <<"Your hero takes the map and looks down at it, the Palace\n";
        cout <<"Looks about one long day's march away, but as your hero\n";
        cout <<"looks back up they see that the hermit is gone! And more\n";
        cout <<"so that the cell door is now ajar! Your hero rolls the\n";
        cout <<"map back up and steps out the door, intrigued by this\n";
        cout <<"palace and what answers lie in wait there. As your hero\n";
        cout <<"crosses the cell door threshold they hear a gush of wind\n";
        cout <<"behind them. They whirl around only to see a wall where\n";
        cout <<"their cell was moments before. Bewildered, the hero\n";
        cout <<"presses onward into the prison...";

        hours--;

        return 'e';

        break;

      // user chose to go to wall
      case 3:
        cout <<"Your hero walks up to the wall, there is nothing but old\n";
        cout <<"stone, and carvings of days spent by previous patrons...\n";
        cout <<"Your hero walks back to the center of the room.\n";
        break;

      // user chose to go to wall
      case 4:
        cout <<"Your hero walks up to the wall, there is nothing but old\n";
        cout <<"stone, and carvings of days spent by previous patrons...\n";
        cout <<"Your hero walks back to the center of the room.\n";
        break;
      default: cout << "\nERROR DEFAULT\n";
    }
  }
}

//No event here
void Grotto::event(std::vector<Character *> &v) {}

//No map yet...
void Grotto::map() {
  for(int i=0;i<100;i++){cout<<"\n";}
  cout << "\nOops! you don't have a map yet!!\n\n";
}
