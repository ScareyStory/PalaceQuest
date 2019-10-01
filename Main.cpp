/**************************************************************************
** Program Name: Main.cpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  Adventure! 
***************************************************************************/
#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include "Character.hpp"
#include "Warrior.hpp"
#include "Rogue.hpp"
#include "Mage.hpp"
#include "Monk.hpp"
#include "Bard.hpp"
#include "Space.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {

 // Introduce game to user
 for(int i=0;i<100;i++){cout<<"\n";}

 cout <<"Welcome to Palace Quest!\n\n";
 cout <<"An adventure game featuring combat, puzzle solving"
      <<" and exploration!\n\n";
 cout <<"Created by Story Caplain at Oregon State University";
 
 // clear screen
 for(int i=0;i<10;i++){cout<<"\n";}

 // 15 "hours" given to complete game
 int hours = 3;

 // while game is not won or lost
 bool playing = true;

 // User's hero's name
 std::string name;

 while(playing==true) {

  // Create Container object, from Container struct in Space.hpp/cpp
  // c points to current location
  Container c;

  // Intro sequence
  cout<<"\n\n";
  cout<<"Your Character wakes up in a dark grotto, " 
      <<"head throbbing with pain...";
  cout<<"\n\n";
  cout<<"As their eyes come into focus they notice they are in a man-made";
  cout<<endl;
  cout<<"structure.\n"; 
  cout<<endl;
  cout<<"To the north is a stone wall, covered in moss and ";
  cout<<endl;
  cout<<"old cobwebs. About 4 feet up on the wall is a barred window.";
  cout<<endl;
  cout<<endl;
  cout<<"To the west is a wall like the one to the north, but without a ";
  cout<<endl;
  cout<<"window at all.";
  cout<<endl;
  cout<<endl;
  cout<<"The south wall is windowless as well.";
  cout<<endl;
  cout<<endl;
  cout<<"The eastern wall is a locked cage door, and behind it a long, dim";
  cout<<endl;
  cout<<"corridor stretches into blackness.";
  cout<<endl;
  cout<<"\nYour Character bends down to look in a reflective puddle.";
  cout<<endl;
  cout<<"In the reflection, who is staring back?" << endl;

  // Prompt user for hero's name
  int val = 1;
  cout << endl;
  cout<<"What is your hero's name?: ";
  getline(cin,name);
  while(val==1) {
    if(cin.fail() || name.length() > 15 || name == "" || isspace(name[0])) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a name 15 Characters or less: ";
      getline(cin,name);
    }   
    else if(!cin.fail()) {
      val = 0;
    }   
  }

  //Vector for team
  vector<Character *> team;

  cout<<"What kind of hero stares back in the reflection?\n"<<endl;

  //User is shown the Character types
  cout<<"1) The Warrior:";
  cout<<"\n   Strong, tall and able to use a battleaxe. Warriors have high";
  cout<<"\n   health, but do medium damage. They have the ability to knock";
  cout<<"\n   down weak walls.\n"<<endl;

  cout<<"2) The Rogue:";
  cout<<"\n   Quick, resourceful and able to use a bow. Rogues have low ";
  cout<<"\n   health but do high damage. They have the ability to unlock";
  cout<<"\n   locked containers.\n"<<endl;

  cout<<"3) The Mage:"; 
  cout<<"\n   Wise, protective and can use a staff. Mages have medium ";
  cout<<"\n   health and low damage. They have the ability to buff the";
  cout<<"\n   damage resistance of their team during battle.\n"<<endl;

  cout<<"4) The Monk:";
  cout<<"\n   Cunning, disciplined and can use a staff. Monks have medium";
  cout<<"\n   health and high damage. They have a small chance ";
  cout<<"\n   to blast their opponent with massive damage.\n"<<endl;

  cout<<"5) The Bard:";
  cout<<"\n   Jovial, team-minded and cannot use a weapon. Bards have ";
  cout<<"\n   medium health and no damage. They have the ability to boost";
  cout<<"\n   the resistance and damage of their team in battle.\n"<<endl;

  int userchoice;
  cout<<"\nWhich type of hero arises today?"<<endl;
  cout<<"Enter a 1, 2, 3, 4 or 5: ";
  cin >> userchoice;

  val = 1;
  while(val==1) {
    if(cin.fail() || userchoice > 5 || userchoice < 1) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a 1, 2, 3, 4 or 5: ";
      cin  >> userchoice;
    }
    else if(!cin.fail()) {
      val = 0;
    }
  }

  //Have user choose their Character.
  Character *user = NULL;
  switch(userchoice) {

    // depending on character choice, instantiate proper
    // object with default attributes
    case 1:
      user = new Warrior(1,0,0,20,80,0,false,false);
      break;
    case 2:
      user = new Rogue(2,0,0,10,40,0,false,false);
      break;
    case 3:
      user = new Mage(3,0,0,0,70,0,false,false);
      break;
    case 4:
      user = new Monk(4,0,0,0,70,0,false,false);
      break;
    case 5:
      user = new Bard(5,0,0,5,70,0,false,false);
      break;
    default: cout<<"\nError, default case reached\n";
  }

  // Set user's name, true means it is for user and not NPC
  user->setName(true, name);

  //Add user's choice to team
  team.push_back(user);

  for(int i=0;i<100;i++){cout<<"\n";}

  bool adventuring = true;

  //BEGIN ADVENTURING!
  while(adventuring==true && hours > 0) {

   //give user info about current space
   c.current->info();

   //store result of check in chk
   //check sees if there is an event at that space
   bool chk = c.current->checker();

   //if there is a battle or puzzle
   if(chk==true) {
     c.current->event(team);
   }

   // if team is dead end game
   if(team.empty()) {
     for(int i=0;i<100;i++){cout<<"\n";}
     cout << "\n\n\nYour hero feels the darkness of death wash over...\n";
     cout << "\nEvil across the land rejoices and fissures open up all\n";
     cout << "across the land. Demons pour out and Evil's army invades...";

     cout << "\n\nYour hero has failed their quest\n\n";
     return 0;
   }

   // if team is not dead keep adventuring
   if(!team.empty()) {
     //Get direction and change spaces
     char dir = c.current->move(hours, team);
     switch(dir) {
       case 'n':
         c.current = c.current->north;
         cout << endl;
         cout << endl;
         cout << hours << " hours remain until the hero is doomed...\n\n";
         cout << "Press enter to continue...";
         cin.ignore();
         cin.ignore();
         for(int i=0;i<100;i++){cout<<"\n";}
         break;
       case 'e':
         c.current = c.current->east;
         cout << endl;
         cout << endl;
         cout << hours << " hours remain until the hero is doomed...\n\n";
         cout << "Press enter to continue...";
         cin.ignore();
         cin.ignore();
         for(int i=0;i<100;i++){cout<<"\n";}
         break;
       case 'w':
         c.current = c.current->west;
         cout << endl;
         cout << endl;
         cout << hours << " hours remain until the hero is doomed...\n\n";
         cout << "Press enter to continue...";
         cin.ignore();
         cin.ignore();
         for(int i=0;i<100;i++){cout<<"\n";}
         break;
       case 's':
         c.current = c.current->south;
         cout << endl;
         cout << endl;
         cout << hours << " hours remain until the hero is doomed...\n\n";
         cout << "Press enter to continue...";
         cin.ignore();
         cin.ignore();
         for(int i=0;i<100;i++){cout<<"\n";}
         break;
       default: 
         adventuring = false;
         playing = false;
     }
   }

   // if out of time end game
   if(hours < 1) {
     for(int i=0;i<100;i++){cout<<"\n";}
     cout << "\n\n\nTime has run out...\n";
     cout << "\nAs the last grain of sand falls through the hourglass\n";
     cout << "fissures crack open through the realm and monstrosities\n";
     cout << "pour out of them...\n\n";
     cout << "The world succumbs to evil\n\n\n";

     // delete team
     for(int i=0; i<team.size(); i++) {
       delete team[i];
     }
     team.clear();
     return 0;
   }

   // break loop in case of dead team
   if(team.empty()) {adventuring = false; playing=false;}

  }

  // If team is alive after final encounter, show winning sequence
  if(!team.empty()) {
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.ignore();
    for(int i=0;i<100;i++){cout<<"\n";} 
    cout << "\n\nFrom a hilltop overlooking the palace is the hermit..\n";
    cout << "He smiles as he feels the darkness leaving the skies and\n";
    cout << "he feels warmth on his face as the black clouds in the sky\n";
    cout << "above dissipate after decades of darkness.\n";
    cout << "He smiles, pulls out a pipe, and relaxes against an old tree";
    cout << endl;
    cout << "\n\"Good job, "<<team[0]->getName()<<", old friend...\"";
    cout << endl;
    cout << endl;
    cout << endl;
    for(int i=0;i<5;i++){cout<<" ";}
    for(int i=0;i<20;i++){cout<<"\u2604";}
    cout << endl;
    for(int i=0;i<5;i++){cout<<" ";}
    cout << "\u2604";
    cout << "      YOU WIN!    ";
    cout << "\u2604";
    cout << endl;
    for(int i=0;i<5;i++){cout<<" ";}
    for(int i=0;i<20;i++){cout<<"\u2604";}
    cout << "\n\n\n\n";

     // delete team
     for(int i=0; i<team.size(); i++) {
       delete team[i];
     }
     team.clear();
  }
 }
 return 0;
}
