/**************************************************************************
** Program Name: CursedValley.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the CursedValley class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "CursedValley.hpp"

#include "Character.hpp"
#include "Enemy.hpp"
#include "Skellybones.hpp"

using std::cout;
using std::cin;
using std::endl;

// constructor sets location items
CursedValley::CursedValley(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

// give user information about where they entered
void CursedValley::info() {

  cout << "\n\n";
  cout << "Your party enters the valley and looks around.\n"; 
  cout << "\nTo the north is a mausoleum or perhaps a crypt.\n\n";
  cout << "To the east is the opening to a forest, webs hang from the\n";
  cout << "trees.\n"; 
  cout << "\nTo the south dead grasses stretch out to an opening to\n"; 
  cout << "the foothills that wrap around the mountains and back to the \n";
  cout << "swamps.\n"; 
  cout << "\nTo the west is the easterly side of the mountain pass\n";
}

// see where character wants to go
char CursedValley::move(int &hours, std::vector<Character*> &v) {

  // direction is represented as N, E, W or S
  char dir;

  // Keep moving loop going until they decide where to go
  bool moving = true;

  // for input validation
  int val = 1;

  while(moving==true) {

    // show user the map if they type y or Y
    char map;
    cout << endl;
    cout << "\n\nWould you like to see a map of the realm before moving?\n";
    cout << "Enter a y to see the map, anything else to not: ";
    cin  >> map; 
    if(map=='y' || map=='Y') {
      this->map();
    }    

    cout << endl;
    cout << "Which way does your hero move?\n";
    cout << "Enter n for north\n";
    cout << "Enter e for east\n";
    cout << "Enter s for south\n";
    cout << "Enter w for west\n";
    cout << "\nDirection: ";

    // for input validation
    // keep asking for input until valid
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

    // clear screen
    for(int i=0;i<100;i++){cout<<"\n";} 

    // will represent direction
    int d;

    // if party has a warrior we will mark it true
    bool warriorFound = false;

    // set cardinal direction to 1,2,3 or 4 for switch statement
    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    switch(d) {
    
      case 1:

        cout << endl;
        cout << "\nYour party approaches the barricaded crypt...\n";
        cout << "Its barricade looks strong but not unbreakable.\n";
        cout << "A warrior could probably break it...\n";

        // check if user wants to enter, if they can
        char crypt;

        // loop through party, if a warrior is found mark bool true
        // and give player the option to break the barricade
        for(int i=0; i<v.size(); i++) {
          if(v[i]->getType()==1) {
            warriorFound = true;
            cout << endl;
            cout << v[i]->getName() << " smashes the barricade easily!\n\n\n";
            cout << "Does your party enter the crypt?\n";
            cout << "Enter y to enter, anything else to not: ";
            cin  >> crypt;

            // if they want to enter return 'n' to move into crypt
            if(crypt=='y'||crypt=='Y') {
              cout << "\n\nYour party wearily enters the crypt...\n\n";
              hours--;
              return 'n';
            }

            // else return user to valley
            else {
              cout<<"\nYour party walks back to the center of the valley\n";
            }
          }

          // if user does not have a warrior in the party
          // return them to center of valley
          else if(i == v.size()-1 && !warriorFound) {
            if(v.size() > 1) {
              cout << "\nYour party does not have a warrior...\n";
              cout << "They walk back to the center of the valley\n\n";
            }
            else {
              cout << "\nYour hero is not a warrior...\n";
              cout << "They walk back to the center of the valley\n\n";
            }
          }
        }
        break;

      // if user wants to go east to the forest, confirm this
      case 2:

        char forest;
        cout << endl;
        cout << "The path to the east leads to the entrance of a forest.\n";
        cout << "The forest seems to stare back at the party...\n";
        cout << "Does your party head into the forest?\n\n";
        cout << "Enter y to head in, anything else to not: ";
        cin  >> forest;

        if(forest=='y'||forest=='Y') {hours--;return 'e';}
        break;

      // if user wants to backtrack south to the foothills, confirm this
      case 3:

        char foothills;
        cout << "\nYour hero looks to the south and sees the opening to\n";
        cout << "the foothills.\n";
        cout << "\nDoes your party head into the foothills?";
        cout << "\nEnter y to head in, anything else to not: ";
        cin  >> foothills;

        if(foothills=='y'||foothills=='Y') {hours--;return 's';}
        break;

      // if user tries to go north let them know they cannot
      case 4:

        char mts;
        cout << "Your hero looks back west to see the mountain pass\n";
        cout << "up above...\n";
        cout << "Does your party venture up into the mountains?\n";
        cout << "Enter y to head up, anything else to not: ";
        cin  >> mts;

        if(mts=='y'||mts=='Y') {hours--;return 'w';}
        break;
    }
  }
}

// Event here is a battle with a low health group of skeletons (skellybones)
void CursedValley::event(std::vector<Character *> &v) {

  // ba1-3 will be used to hold the difference between the boss's attack
  // and each party member's defense
  int ba1 = 0;
  int ba2 = 0;
  int ba3 = 0;
  int kill = 0;

  cout << endl;

  // if there is a bard in the party they play a song
  for(int i = 0; i < v.size(); i++) {
    if(v[i]->getType()==5) {
      cout << endl;
      cout << v[i]->getName() << " begins singing a song to break up\n";
      cout << "the gloom of the valley...\n\n";
    }
  }

  cout << "Suddenly out from the fog, three figures begin to emerge!\n";
  cout << "They do not utter a word as they walk closer, creaking as\n";
  cout << "they do. When they get close enough the party sees the\n";
  cout << "mysterious figures for what they are, undead...\n";
  cout << "The skeletal beings unsheath their swords and clack their\n";
  cout << "jaws as they march into battle range!\n\n";

  // Create a Skeleton object
  Enemy *boss = new Skellybones(0,0,0,60);

  bool fighting = true;

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
      if(cin.fail() || 
        (bchoice != 1 && bchoice != 2 
        && bchoice != 3 && bchoice != 1337)) {
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
    
    // if user chose to give out health potions
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


    // ADMIN function to kill character
    else if(bchoice==1337) {
      for(int i=0; i<v.size(); i++) {
        cout << "\n\nADMIN CODE ENTERED WHO DO YOU WANT TO KILL?\n\n";
        cout << "Kill " << v[i]->getName() << "? (Enter 1): ";
        cin >> kill;
        if(kill==1) {
          v[i]->setStrength(9999);
          v[i]->setStrength(9999);
        }
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

void CursedValley::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass                                                ^   \n";
 cout<<" 5)Valley (You are here!!!!!!!!!!!!)                       v   \n";
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
