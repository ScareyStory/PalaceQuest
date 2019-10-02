/**************************************************************************
** Program Name: Forest.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Forest class.
**************************************************************************/
#include <iostream>
#include <vector>
#include <limits>

#include "Forest.hpp"

#include "Character.hpp"
#include "Enemy.hpp"
#include "Spiders.hpp"

using std::cout;
using std::cin;
using std::endl;

Forest::Forest(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Forest::info() {

  cout << "\n\n";
  cout << "The party makes it to a clearing in the forest, and stop to\n";
  cout << "look around.\n"; 
  cout << "\nTo the north looks like what could be an exit\n";
  cout << "\nTo the east the forest stretches for many miles\n\n";
  cout << "To the south a powerful aura is felt through the dense trees\n";
  cout << "\nTo the west is the valley your party ventured through...\n";
}

char Forest::move(int &hours, std::vector<Character*> &v) {

  char dir;
  bool moving = true;
  int val = 1;

  while(moving==true) {
    char map;
    cout << endl;
    cout << "\n\nWould you like to see a map of the realm before moving?\n";
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

    if(dir=='s' || dir=='S')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='n' || dir=='N') {d=3;}
    else                          {d=4;}

    switch(d) {
    
      case 1:

        cout << endl;
        cout << "\nYour party approaches the southern part of the\n";
        cout << "clearing. A magic aura stops your party in its tracks\n";
        cout << "\nA mage or monk might be useful here...\n";

        // used to check if there is a monk or mage to enter shrine
        char shrine;

        // loop through party and check for mage or monk
        for(int i=0; i<v.size(); i++) {

          // if found they wave the aura away
          if(v[i]->getType()==3 || v[i]->getType()==4) {
            cout << endl;
            cout << v[i]->getName() << " waves away the aura!\n";
            cout << "Does your party continue south?\n\n";
            cout << "Enter y to enter, anything else to not: ";
            cin  >> shrine;

            // if user chooses to enter
            if(shrine=='y'||shrine=='Y') {
              cout << "\n\nYour party pushes southward...\n\n";
              hours--;
              return 's';
            }

            // if user chooses not to enter
            else {
              cout<<"\nYour party walks back to the clearing\n";
            }
          }

          // if at end of party vector, then no mage or monk found
          else if(i == v.size()-1) {

            // if one member party inform them they cannot enter
            if(i==0) {
              cout << "\nYour hero is not a mage or monk...\n";
              cout << "They walk back to the clearing\n\n";
            }

            // if 2 or 3 member party inform them they cannot enter
            else {
              cout << "\nYour party does not have a mage or monk...\n";
              cout << "They walk back to the clearing\n\n";
            }
          }
        }
        break;

      case 2:

        cout << endl;
        cout << "The path to the east leads into ever denser forest.\n";
        cout << "Its eastern end nowhere in sight...\n";
        cout << "Your hero makes the decision to stay in the clearing.\n";

        break;

      case 3:

        char exit;
        cout << "\nYour hero looks to the north and sees what looks like\n";
        cout << "an exit out of the forest.\n";
        cout << "Does your party go northwards?\n\n";
        cout << "Enter y to head north, anything else to not: ";
        cin  >> exit;

        if(exit=='y'||exit=='Y') {hours--;return 'n';}
        break;

      case 4:

        char vly;
        cout << "Your hero looks back west to see the exit to the valley\n";
        cout << "Does your party venture back to the valley?\n";
        cout << "Enter y to head back, anything else to not: ";
        cin  >> vly;

        if(vly=='y'||vly=='Y') {hours--;return 'w';}
        break;
    }
  }
}

void Forest::event(std::vector<Character *> &v) {

  int ba1 = 0;
  int ba2 = 0;
  int ba3 = 0;

  cout << "\nSuddenly the spider from the prison runs across your path!\n";
  cout << "As it does three giant spiders drop down from above!\n";
  cout << "As their pincers snap they charge!\n\n";

  Enemy *boss = new Spiders(0,0,0,60);

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

void Forest::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass                                                ^   \n";
 cout<<" 5)Valley                                                  v   \n";
 cout<<" 6)Crypt                                                 * * * \n";
 cout<<" 7)Forest (You are here!!!!!!!!!!!!)                     * 9 * \n";
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
