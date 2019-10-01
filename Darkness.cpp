/**************************************************************************
** Program Name: Darkness.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the Darkness class.
**************************************************************************/
#include <iostream>
#include <vector>

#include "Darkness.hpp"

#include "Character.hpp"
#include "Enemy.hpp"
#include "Nightsprites.hpp"
#include "Evil.hpp"

using std::cout;
using std::cin;
using std::endl;

Darkness::Darkness(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void Darkness::info() {
  char map;
  cout << "\nWould you like to see a map of the realm, one last time?\n";
  cout << "Enter a y to see the map, anything else to not: ";
  cin  >> map; 
  if(map=='y' || map=='Y') {
    for(int i=0;i<100;i++){cout<<"\n";} 
    this->map();
  }    
}

//Game ends no need to move
char Darkness::move(int &hours, std::vector<Character*> &v) {}

//Double battle!
void Darkness::event(std::vector<Character *> &v) {

  cout << "\nPress enter to continue...";
  cin.ignore();
  cin.ignore();
  for(int i=0;i<100;i++){cout<<"\n";}

  int ba1 = 0;
  int ba2 = 0;
  int ba3 = 0;

  cout << "\n\n";
  cout << "Your hero arrives at the lakeshore outside the palace";
  if(v.size()>1){cout<<" along with their party";}
  cout << ".\n";

  cout << "Down from the palace steps walks a gaunt figure.\n";
  cout << "It is quite tall, as tall as one and a half men.\n";
  cout << "The being looks to be a butler of sorts, with a\n";
  cout << "nice but centuries outdated suit. It does not\n";
  cout << "have a face, but from a head pitch black as midnight\n";
  cout << "two cool grey eyes stare at your hero\n\n\n";
  cout << "Without speaking it beckons ";
  if(v.size()>1){cout<<"the party ";}
  else{cout<<"your hero ";}
  cout << "into the palace\n";
  cout << "Your hero walks up the steps and into the throne room...\n";
  cout << "Inside the room five dark clouds in humanoid forms crackle\n";
  cout << "with dark lightning. They stand at the base of a large and\n";
  cout << "grotesque throne. On the throne sits a being encased in a \n";
  cout << "blinding red aura. It laughs deeply, sending cold needles\n";
  cout << "down your hero's spine, the laugh is thick with malice\n";
  cout << "It moves as if to wave a hand, and the five\n";
  cout << "humanoid creatures float forward! \n\n\n";
  cout << "The Nightsprites attack!\n";

  cout << endl;

  // Create the nightsprites object
  Enemy *boss = new Nightsprites(0,0,0,150);

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

  // For first and second fighting loops
  bool fighting1 = true;
  bool fighting2 = true;

  while(fighting1==true) {

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

        //Delete dead users end game if hero dies
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

    if(boss->getStrength() <= 0) {fighting1=false;}
  }
  delete boss;

  //Reset battle variables from above
  bchoice = 0;
  val = 1;
  teamAttack = 0;
  defense1 = 0;
  defense2 = 0;
  defense3 = 0;
  aboosts = 0;
  dboosts = 0;
  bossAttack = 0;
  bossDefense = 0;
  damage = 0;
  excess = 0;
  excess1 = 0;
  excess2 = 0;
  excess3 = 0;

  //EVIL ATTACKS!

  cout << "\n\n";
  cout << "The being in the throne stands up and begins to clap...\n";
  cout << "It walks down the steps of its throne and comes up to your\n";
  cout << "hero. Closer now, it can be seen through its aura of dark\n";
  cout << "energy. A Demon stares out from the aura, but it is a\n";
  cout << "familiar one...\n\n";
  cout << "Your hero remembers how it is that they came to this realm.\n";
  cout << "Years before, instead of letting themselves be killed by the\n";
  cout << "demon, this Evil, they siphoned the Evil's aura and used it\n";
  cout << "to send themselves forward in time. In that time the Evil\n";
  cout << "had corrupted the realm, and your hero knows it is finally\n";
  cout << "time to exact their revenge...\n\n\n";
  cout << "The Evil floats back knowing a fight is imminent, and ";
  if(v.size()>1){cout << "your party\n";}
  else{cout << "your hero\n";}
  cout << "prepare for the ultimate battle!\n";
 
  Enemy *lastBoss = new Evil(0,0,0,500);

  while(fighting2==true) {

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
      lastBoss->defending();
      bossDefense = lastBoss->getDefense();

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
        excess = lastBoss->setArmor(damage);

        // if boss has no armor or armor is broken
        // reduce health by excess
        lastBoss->setStrength(excess);
      }

      // if boss is still alive, it now attacks
      if(lastBoss->getStrength() > 0) {

        // reset defensive variables
        dboosts = 0;
        defense1 = 0;
        defense2 = 0;
        defense3 = 0;

        lastBoss->attacking();

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
        bossAttack = lastBoss->getAttack();
        cout << endl;
        cout << "Enemy attacks for " << lastBoss->getAttack() << " damage";
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

    if(boss->getStrength() <= 0) {fighting2=false;}
  }
  delete lastBoss;
}

void Darkness::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
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
 cout<<" !)Palace (You are here!!!!!!!!!!!!)                       v   \n";
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
