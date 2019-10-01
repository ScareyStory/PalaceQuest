/**************************************************************************
** Program Name: Prison.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Prison class.
**************************************************************************/
#include <iostream>
#include <vector>

#include "Prison.hpp"

#include "Character.hpp"
#include "Warrior.hpp"
#include "Rogue.hpp"
#include "Mage.hpp"
#include "Monk.hpp"
#include "Bard.hpp"

#include "Enemy.hpp"
#include "Warden.hpp"

using std::cout;
using std::cin;
using std::endl;

Prison::Prison(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

//Give space info
void Prison::info() {

  cout <<"\nYou enter the prison and look about, seeing 4 cells each \n";
  cout <<"with an occupant in them along the northern wall.\n"; 
  cout <<"\nTo the south is a wall with 2 keys on hooks\n";
  cout <<"\nTo the west is the wall that was before your cell door\n";
  cout <<"\nTo the east is a thick iron double door, locked tight.\n";

}

//move party
char Prison::move(int &hours, std::vector<Character*> &v) {

  char dir;
  bool moving = true;
  int val = 1;

  while(moving==true) {
    
    for(int i=0;i<5;i++){cout<<"\n";}
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

        cout << "\nYour hero sees the now empty jail cells from earlier\n";
        cout << "Your hero walks back to the center of the room\n";

        break;

      case 2:

        cout << "\n\n";
        cout << "Your hero walks around the feasting spiders and to the\n";
        cout << "iron doors the warden came through. The sounds of a\n";
        cout <<"swamp come through the door, and the party goes through\n";
        cout << "the door and out.\n";

        hours--;
        return 'e';

        break;

      case 3:

        cout << "The southern wall has more empty cells, with nothing\n";
        cout << "of importance inside them. The party walks back to the\n";
        cout << "center of the room.\n";

        break;

      case 4:

        cout << "Your hero looks back to where his cell used to be, and\n";
        cout << "sees now only a wall, with no evidence a cell was ever\n";
        cout << "there at all\n";

        break;
    }
  }
}

void Prison::event(std::vector<Character *> &v) {

  //for new party members
  Character *npc1 = NULL;
  Character *npc2 = NULL;

  int usertype = v[0]->getType();

  cout << "\nYour hero grabs the keys and heads over to the cells.\n\n";

  int val = 1;
  int choice1;
  int choice2;


  //////////////////////////////////////
  //SWITCH BASED ON USER'S HERO TYPE  //
  //THEIR TYPE WILL NOT BE IN A CELL! //
  //////////////////////////////////////

  
  switch(usertype) {
    case 1:
      cout << "\n\n";
      cout << "In cell 1 is a woman, sleeping up against the wall...\n";
      cout << "Type: Rogue\n";
      cout << endl;
      cout << "In cell 2 is a man with a beard and robe, sleeping\n";
      cout << "Type: Mage\n";
      cout << endl;
      cout << "In cell 3 is a bald sinewy man in a robe, sleeping\n";
      cout << "Type: Monk\n";
      cout << endl;
      cout << "In cell 4 is an overweight man in a tunic, sleeping\n";
      cout << "Type: Bard\n";
      cout << endl;

      cout << "\nWhich two do you save?\n";
      cout << endl; 
      cout << "Enter the cell number of the first one you wish to save: ";
      cin  >> choice1;
      while(val==1) {
        if(cin.fail() || choice1 < 1 || choice1 > 4) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice1;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');
      
      val = 1;
      cout << "Enter the cell number of the second one you wish to save: ";
      cin  >> choice2;
      while(val==1) {
        if(cin.fail()||choice2 < 1||choice2 > 4||choice2 == choice1) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Note: You cannot save the same person twice...\n";
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice2;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');

      //Choose first party member
      switch(choice1) {
        case 1: npc1 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc1 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc1 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc1 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc1\n";
      }
      //Choose second party member
      switch(choice2) {
        case 1: npc2 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc2 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc2 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc2 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc2\n";
      }
      break;

    case 2:

      cout << "In cell 1 is a warrior, sleeping up against the wall...\n";
      cout << "Type: Warrior\n";
      cout << endl;
      cout << "In cell 2 is a man with a beard and robe, sleeping\n";
      cout << "Type: Mage\n";
      cout << endl;
      cout << "In cell 3 is a bald sinewy man in a robe, sleeping\n";
      cout << "Type: Monk\n";
      cout << endl;
      cout << "In cell 4 is an overweight man in a tunic, sleeping\n";
      cout << "Type: Bard\n";
      cout << endl;

      cout << "Which two do you save?\n";
      
      cout << "Enter the cell number of the first one you wish to save: ";
      cin  >> choice1;
      while(val==1) {
        if(cin.fail() || choice1 < 1 || choice1 > 4) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice1;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');
      
      val = 1;
      cout << "Enter the cell number of the second one you wish to save: ";
      cin  >> choice2;
      while(val==1) {
        if(cin.fail()||choice2 < 1||choice2 > 4||choice2 == choice1) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Note: You cannot save the same person twice...\n";
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice2;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');

      switch(choice1) {
        case 1: npc1 = new Warrior(1,0,0,20,80,0,false,false);break;
        case 2: npc1 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc1 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc1 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc1\n";
      }
      switch(choice2) {
        case 1: npc2 = new Rogue(1,0,0,20,80,0,false,false);break;
        case 2: npc2 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc2 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc2 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc2\n";
      }
      break;
      
    case 3:
      
      cout << "In cell 1 is a woman, sleeping up against the wall...\n";
      cout << "Type: Rogue\n";
      cout << endl;
      cout << "In cell 2 is a warrior, sleeping\n";
      cout << "Type: Warrior\n";
      cout << endl;
      cout << "In cell 3 is a bald sinewy man in a robe, sleeping\n";
      cout << "Type: Monk\n";
      cout << endl;
      cout << "In cell 4 is an overweight man in a tunic, sleeping\n";
      cout << "Type: Bard\n";
      cout << endl;

      cout << "Which two do you save?\n";
      
      cout << "Enter the cell number of the first one you wish to save: ";
      cin  >> choice1;
      while(val==1) {
        if(cin.fail() || choice1 < 1 || choice1 > 4) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice1;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');
      
      val = 1;
      cout << "Enter the cell number of the second one you wish to save: ";
      cin  >> choice2;
      while(val==1) {
        if(cin.fail()||choice2 < 1||choice2 > 4||choice2 == choice1) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Note: You cannot save the same person twice...\n";
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice2;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');

      switch(choice1) {
        case 1: npc1 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc1 = new Warrior(1,0,0,20,80,0,false,false);break;
        case 3: npc1 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc1 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc1\n";
      }
      switch(choice2) {
        case 1: npc2 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc2 = new Warrior(1,0,0,20,80,0,false,false);break;
        case 3: npc2 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc2 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc2\n";
      }
      break;
      
    case 4:
      
      cout << "In cell 1 is a woman, sleeping up against the wall...\n";
      cout << "Type: Rogue\n";
      cout << endl;
      cout << "In cell 2 is a man with a beard and robe, sleeping\n";
      cout << "Type: Mage\n";
      cout << endl;
      cout << "In cell 3 is a warrior, sleeping\n";
      cout << "Type: Warrior\n";
      cout << endl;
      cout << "In cell 4 is an overweight man in a tunic, sleeping\n";
      cout << "Type: Bard\n";
      cout << endl;

      cout << "Which two do you save?\n";
      
      cout << "Enter the cell number of the first one you wish to save: ";
      cin  >> choice1;
      while(val==1) {
        if(cin.fail() || choice1 < 1 || choice1 > 4) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice1;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');
      
      val = 1;
      cout << "Enter the cell number of the second one you wish to save: ";
      cin  >> choice2;
      while(val==1) {
        if(cin.fail()||choice2 < 1||choice2 > 4||choice2 == choice1) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Note: You cannot save the same person twice...\n";
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice2;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');

      switch(choice1) {
        case 1: npc1 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc1 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc1 = new Warrior(1,0,0,20,80,0,false,false);break;
        case 4: npc1 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc1\n";
      }
      switch(choice2) {
        case 1: npc2 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc2 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc2 = new Warrior(1,0,0,20,80,0,false,false);break;
        case 4: npc2 = new Bard(5,0,0,5,70,0,false,false);break;
        default: cout<<"\nError in adding npc2\n";
      }
      break;

    case 5:   

      cout << "In cell 1 is a woman, sleeping up against the wall...\n";
      cout << "Type: Rogue\n";
      cout << endl;
      cout << "In cell 2 is a man with a beard and robe, sleeping\n";
      cout << "Type: Mage\n";
      cout << endl;
      cout << "In cell 3 is a bald sinewy man in a robe, sleeping\n";
      cout << "Type: Monk\n";
      cout << endl;
      cout << "In cell 4 is a warrior, sleeping\n";
      cout << "Type: Warrior\n";
      cout << endl;

      cout << "Which two do you save?\n";
      
      cout << "Enter the cell number of the first one you wish to save: ";
      cin  >> choice1;
      while(val==1) {
        if(cin.fail() || choice1 < 1 || choice1 > 4) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice1;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');
      
      val = 1;
      cout << "Enter the cell number of the second one you wish to save: ";
      cin  >> choice2;
      while(val==1) {
        if(cin.fail()||choice2 < 1||choice2 > 4||choice2 == choice1) {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "\nOops! Invalid input." << endl;
          cout << "Note: You cannot save the same person twice...\n";
          cout << "Enter a 1, 2, 3 or 4: ";
          cin  >> choice2;
        }   
        else if(!cin.fail()) {
          val = 0;
        }       
      } 
      cin.clear();
      cin.ignore(256, '\n');

      switch(choice1) {
        case 1: npc1 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc1 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc1 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc1 = new Warrior(1,0,0,20,80,0,false,false);break;
        default: cout<<"\nError in adding npc1\n";
      }
      switch(choice2) {
        case 1: npc2 = new Rogue(2,0,0,10,40,0,false,false);break;
        case 2: npc2 = new Mage(3,0,0,0,70,0,false,false);break;
        case 3: npc2 = new Monk(4,0,0,0,70,0,false,false);break;
        case 4: npc2 = new Warrior(1,0,0,20,80,0,false,false);break;
        default: cout<<"\nError in adding npc2\n";
      }
      break;
  }
  cout << endl;

  //add team members
  v.push_back(npc1);
  v.push_back(npc2);

  std::string s = "";

  //name npcs's
  v[1]->setName(false, s);
  v[2]->setName(false, s);

  // clear screen
  for(int i=0;i<100;i++){cout<<"\n";}

  //Introduce members
  cout << "The two cages open, and their occupants awake and come out\n\n";

  cout << "\"Thank you! My name is " << v[1]->getName() <<"\""<< endl;
  
  cout << "\"Thank you! My name is " << v[2]->getName() <<"\""<< endl;
  cout << endl;

  cout << v[2]->getName() <<" kicks open a chest in the room to reveal\n";
  cout << "three health potions, a battleaaxe, a bow and a staff\n";
  
  //Give out axe
  if(v[0]->getType()==1) {
    cout << endl;
    cout << "Your hero picks up the battleaxe\n"; 
    v[0]->giveWeapon(); 
  }
  else if(v[1]->getType()==1) {
    cout << endl;
    cout << v[1]->getName() << " picks up the battleaxe\n"; 
    v[1]->giveWeapon(); 
  }
  else if(v[2]->getType()==1) {
    cout << endl;
    cout << v[2]->getName() << " picks up the battleaxe\n"; 
    v[2]->giveWeapon(); 
  }
  else{cout << "\nThere are no warriors in your party to wield the axe\n";}
  
  //give out bow
  if(v[0]->getType()==2) {
    cout << endl;
    cout << "Your hero picks up the bow\n";
    v[0]->giveWeapon(); 
  }
  else if(v[1]->getType()==2) {
    cout << endl;
    cout << v[1]->getName() << " picks up the bow\n"; 
    v[1]->giveWeapon(); 
  }
  else if(v[2]->getType()==2) {
    cout << endl;
    cout << v[2]->getName() << " picks up the bow\n"; 
    v[2]->giveWeapon(); 
  }
  else {cout << "\nThere are no rogues in your party to wield the bow\n";}

  //Give out staff
  if(v[0]->getType()==3 || v[0]->getType()==4) {
    cout << endl;
    cout << "Your hero picks up the staff\n"; 
    v[0]->giveWeapon(); 
  }
  else if(v[1]->getType()==3 || v[1]->getType()==4) {
    cout << endl;
    cout << v[1]->getName() << " picks up the staff\n"; 
    v[1]->giveWeapon(); 
  }
  else if(v[2]->getType()==3 || v[2]->getType()==4) {
    cout << endl;
    cout << v[2]->getName() << " picks up the staff\n"; 
    v[2]->giveWeapon(); 
  }
  else {cout << "\nNo monks/mages in your party to wield the staff\n";}

  //Give out hpots
  cout << endl;
  for(int i=0; i<v.size(); i++) {
    cout << v[i]->getName() << " picks up a health potion!\n";
    v[i]->giveHpot(1);
  }

  cout<<"\nPress enter to continue...";
  cin.clear();
  cin.ignore(10000,'\n'); 

  // clear screen
  for(int i=0;i<100;i++){cout<<"\n";}

  cout << endl;
  cout << "Your hero's newfound companions tell your hero that there is\n";
  cout << "a ruthless warden who will be back any moment!\n";
  cout << "just as they finish telling you the iron doors to the east\n";
  cout<< "smash open and a half man, half troll abomination saunters in\n";
  cout << "\nThe beast bellows out a roar and picks up his club!\n";
  cout << "It looks like it wants a fight!!!\n\n\n";

  Enemy *boss = new Warden(0,0,0,100);

  bool fighting = true;

  // ba1-3 will be used to hold the difference between the boss's attack
  // and each party member's defense
  int ba1 = 0;
  int ba2 = 0;
  int ba3 = 0;

  //BATTLE!
  while(fighting==true) {
  
    // bchoice is battle choice 
    // 1 is fight, 2 is health potion, 3 is info
    int bchoice = 0;

    // for input validation
    int val = 1;

    // will hold the combined value of the team's attack
    double teamAttack = 0;

    // will hold the defense for each party member's roll
    int defense1 = 0;
    int defense2 = 0;
    int defense3 = 0;

    // if a bard is on the team aboosts is a multiplier 
    // to the team's attacks
    int aboosts = 0;

    // if a mage is on the team dboosts is a multiplier 
    // to the team's defenses
    int dboosts = 0;

    // Attack value that the boss rolls
    int bossAttack = 0;

    // Defense value that the boss rolls
    int bossDefense = 0;

    // Holds the excess of party damage over boss defense
    int damage = 0;

    // Will hold any damage that exceeds boss's armor
    int excess = 0;

    // Excess1, 2, and 3 will hold boss damage that exceeds
    // the character's armor
    int excess1 = 0;
    int excess2 = 0;
    int excess3 = 0;

    // Used in confirming if player wants to use a health potion
    char hpc;

    cout << "\nWhat does your party do?\n";
    cout << "1) Attack\n";
    cout << "2) Drink a Health Potion\n";
    cout << "3) Party info\n";
    cout << "Choice: ";

    // take in user choice and validate it
    cin  >> bchoice;
    while(val==1) {
      if(cin.fail() || bchoice < 1 || bchoice > 3) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1, 2 or 3: ";
        cin  >> bchoice;
      }
      else if(!cin.fail()) {
        val = 0;
      }
    }
    cin.clear();
    cin.ignore(256, '\n');

    // clear screen
    for(int i=0;i<100;i++){cout<<"\n";}

    // if user wants to fight
    if(bchoice==1) {

      // reset teamAttack and aboosts
      teamAttack = 0;
      aboosts = 0;

      // loop through party vector and get their attack values/boosts
      for(int i=0; i<v.size(); i++) {
        aboosts += v[i]->attacking();
        teamAttack += v[i]->getAttack();
      }

      // calculate boss defense then store it in bossDefense
      boss->defending();
      bossDefense = boss->getDefense();

      // if aboosts holds a 1 boost attack by 15
      if(aboosts==1) {
        teamAttack +=15;
      }
      // if aboosts holds a 2 boost attack by 35
      else if(aboosts==2) {
        teamAttack +=35;
      }
      // if aboosts holds a 3 boost attack by 55
      else if(aboosts==3) {
        teamAttack +=55;
      }

      // if teamAttack exceeds bossDefense
      // store difference in damage
      if(teamAttack > bossDefense) {
        damage = teamAttack - bossDefense;

        // account for possible negative damage
        if(damage < 0){damage=0;}

        // if damage is above zero first reduce boss armor
        // anything left after reducing armor is stored in excess
        excess = boss->setArmor(damage);

        // if boss has no armor or armor is broken
        // reduce health by excess
        boss->setStrength(excess);
      }

      // if boss is still alive, it now attacks
      if(boss->getStrength() > 0) {

        // reset defensive variables
        dboosts = 0;
        defense1 = 0;
        defense2 = 0;
        defense3 = 0;

        boss->attacking();

        // loop through team vector and store their
        // defense values in defense1, 2 and 3
        for(int i=0; i<v.size(); i++) {
          dboosts += v[i]->defending();
          if(i==0) {
            defense1 += v[i]->getDefense();
          }
          else if(i==1) {
            defense2 += v[i]->getDefense();
          }
          else if(i==2) {
            defense3 += v[i]->getDefense();
          }
        }

        // if there is a mage in the party boost defense
        // of each party member by 5
        if(dboosts > 0) {
          defense1 += 5;
          
          // if at least 2 members alive
          if(v.size() > 1) {
            defense2 +=5;
          }
          
          // if all 3 members alive
          if(v.size() > 2) {
            defense3 +=5;
          }
        }

        // Store boss's attack value in bossAttack
        bossAttack = boss->getAttack();
        cout << endl;
        cout << "Enemy attacks for " << boss->getAttack() << " damage";
        cout << endl;

        // loop through vector and get each party member's
        // defense, a defense of 1000 is a perfect dodge/parry
        for(int i=0; i<v.size(); i++) {
          if(i==0) {
            cout << endl;
            if(defense1>=1000) {
              cout << v[i]->getName() << " avoids all damage!\n";
            }
            else if(defense1<1000) {
              cout << v[i]->getName() << " defends with " <<
                      defense1 << " guard\n";
            }
            // store bossAttack - party member defense in ba1
            ba1 = bossAttack - defense1;

            // account for a negative value
            if(ba1 < 0) {ba1=0;}

            // a positive ba1 is first subtracted from 
            // the party member's armor
            excess1 = v[i]->setArmor(ba1);

            // any excess after reducing armor is reduced from
            // strength a.k.a. health
            v[i]->setStrength(excess1);
          }

          else if(i==1) {
            cout << endl;
            if(defense2>=1000) {
              cout << v[i]->getName() << " avoids all damage!\n";
            }
            else if(defense1<1000) {
              cout << v[i]->getName() << " defends with " <<
                      defense2 << " guard\n";
            }
            // store bossAttack - party member defense in ba2
            ba2 = bossAttack - defense2;

            // account for a negative value
            if(ba2 < 0) {ba2=0;}

            // a positive ba2 is first subtracted from 
            // the party member's armor
            excess2 = v[i]->setArmor(ba2);

            // any excess after reducing armor is reduced from
            // strength a.k.a. health
            v[i]->setStrength(excess2);           
          }

          else if(i==2) {
            cout << endl;
            if(defense3>=1000) {
              cout << v[2]->getName() << " avoids all damage!\n";
            }
            else if(defense3<1000) {
              cout << v[2]->getName() << " defends with " <<
                      defense3 << " guard\n";
            }
            // store bossAttack - party member defense in ba2
            ba3 = bossAttack - defense3;

            // account for a negative value
            if(ba3 < 0) {ba3=0;}

            // a positive ba2 is first subtracted from 
            // the party member's armor
            excess3 = v[i]->setArmor(ba3);

            // any excess after reducing armor is reduced from
            // strength a.k.a. health
            v[i]->setStrength(excess3);           
          } 
        } // end of defense for loop

        // Delete dead characters
        // if hero is dead delete whole team
        for(int i=0; i<v.size(); i++) {
          if(v[0]->getStrength() <= 0) {
            for(int i=0; i<v.size(); i++) {
              delete v[i];
            }
            v.clear();            
            return;
          }
          else if(i > 0 && v[i]->getStrength() <= 0) {
            delete v[i];
            v.erase(v.begin()+i);
          }
        }
      } // end of if boss alive conditional
    } // end of battle choice = 1 conditional
    
    // if user choosed to give out health potions
    else if(bchoice==2) {

      for(int i=0; i<v.size(); i++) {
        cout << "Would you like to use a health potion on "
              << v[i]->getName() << "?\n";
        cout << "Enter a y for yes, or anything else for no: ";
        cin  >> hpc;
        if(hpc == 'y' || hpc == 'Y') {
          v[i]->hp();
        }
        cout << endl;
      }
    }
    
    // if user requested info
    else {
      cout << "\n\n";
      for(int i=0;i<v.size();i++) {
        v[i]->info();
      }   
      cout << "\n\n";
    }

    if(boss->getStrength() <= 0) {fighting=false;}
  }
  delete boss;

  // Team recovers from battle
  for(int i=0; i<v.size(); i++) {
    v[i]->recover();
  }
}

void Prison::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison (You are here!!!!!!!!!!!!)                     * ! * \n";
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
