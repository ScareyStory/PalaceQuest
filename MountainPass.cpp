/**************************************************************************
** Program Name: MountainPass.cpp
** Name:         Story Caplain
** Date:         03/10/19
** Description:  This is the cpp file for the MountainPass class.
**************************************************************************/
#include <iostream>
#include <vector>

#include "MountainPass.hpp"

#include "Character.hpp"
#include "Enemy.hpp"
#include "Yeti.hpp"

using std::cout;
using std::cin;
using std::endl;

MountainPass::MountainPass(int hp, int rs, int ba, int b, int s, bool c) :
  Space(hp,rs,ba,b,s,c) {}

void MountainPass::info() {

  cout << "\n\n";
  cout << "Your party, valuing time over safety heads into the mountains\n";
  cout << "The wind begins howling through the narrow but steep pass and\n";
  cout << "your hero cannot tell if it is the wind, or something else...\n";

}
char MountainPass::move(int &hours, std::vector<Character*> &v) {

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

    if(dir=='n' || dir=='N')      {d=1;}
    else if(dir=='e' || dir=='E') {d=2;}
    else if(dir=='s' || dir=='S') {d=3;}
    else                          {d=4;}

    switch(d) {
    
      case 1:

        cout << "\nYour hero looks to the north and sees only an\n";
        cout << "unscalable mountain wall...\n";
        cout << "Your hero turns back to the middle of the pass\n";

        break;

      case 2:

        char valley;
        cout << endl;
        cout << "The path to the east leads down to a valley thick with\n";
        cout << "a dark ominous fog\n\n";
        cout << "Does your party head into the valley?\n";
        cout << "Enter y to head down, anything else to not: ";
        cin  >> valley;

        if(valley=='y'||valley=='Y') {hours--;return 'e';}
        break;

      case 3:

        cout << "\nYour hero looks to the south and sees only an\n";
        cout << "unscalable mountain wall...\n";
        cout << "Your hero turns back to the middle of the pass\n";

        break;

      case 4:

        char swamp;
        cout << "Your hero looks back west to see the swamps far below\n";
        cout << "Would you like to head back to the swamps?\n";
        cout << "\nEnter y to head back, anything else to not: ";
        cin  >> swamp;

        if(swamp=='y'||swamp=='Y') {hours--;return 'w';}
        break;
    }
  }
}

void MountainPass::event(std::vector<Character *> &v) {

  // will hold the boss's attack value against each character
  int ba1 = 0;
  int ba2 = 0;
  int ba3 = 0;

  // Given changes to true once stone is given
  bool given = false;

  // stone holds user input choice
  char stone;

  cout << endl;
  cout << "Your party finds a dead traveler in the pass, his back is\n";
  cout << "slashed open and his satchel has spilled in the snow\n";
  if(v.size()>1){
    cout << v[1]->getName() << " touches the body.\n";
    cout << "\"Still warm... that bodes poorly...\"\n";
  }
  else{cout << "The body is still warm...\n";}

  cout << "Spilled in the snow is a revive stone!\n\n";

  cout << "Who would you like to give the revive stone to?\n";
  cout << "\nNote: If your hero dies you lose!\n";

  // Loop through team vector and ask user who they want to give
  // the revive stone to
  for(int i=0; i<v.size(); i++) {
    cout << "\nWould you like to give the stone to "<<v[i]->getName();
    cout << "\nEnter a y to give, anything else to not: ";
    cin  >> stone;
    if(stone=='y'||stone=='Y') {
      v[i]->giveRstone();
      cout << endl;
      cout << v[i]->getName() << " picks up the revive stone!\n";
      i = v.size();
      given = true;
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

/*
  if(v.size()==3) {
    cout << "\nEnter a 1 to give the stone to your hero, "<<v[0]->getName();
    cout << "\nEnter a 2 to give the stone to " << v[1]->getName();
    cout << "\nEnter a 3 to give the stone to " << v[2]->getName();
  }
  else if(v.size()==2) {
    cout << "\nEnter a 1 to give the stone to your hero, "<<v[0]->getName();
    cout << "\nEnter a 2 to give the stone to " << v[1]->getName();
  }
  else {
    cout << "\n"<<v[0]->getName()<<" picks up the revive stone.\n";
    stone = 0;
  }

  if(v.size() == 2) {
    cout << "\nChoice: ";
    cin >> stone;
    val = 1;
    while(val==1) {
      if(cin.fail() || stone > 2 || stone < 1) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1 or 2: ";
        cin  >> stone;
      }
      else if(!cin.fail()) {
        val = 0;
      }
    }
  }
  else if(v.size() == 3) {
    cout << "\nChoice: ";
    cin >> stone;
    val = 1;
    while(val==1) {
      if(cin.fail() || stone > 3 || stone < 1) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 1, 2 or 3: ";
        cin  >> stone;
      }
      else if(!cin.fail()) {
        val = 0;
      }
    }
  }

  //Change boolean value
  v[stone-1]->giveRstone();
*/

  cout << "\n\nThe howling of the wind begins sounding ever more like\n";
  cout << "that of a man or animal. As the blizzard was thickening\n";
  cout << "your hero begins hearing a rhythmic thumping from the east\n";
  cout << "In the snow a massive bipedal figure starts coming into focus\n";
  cout << "As it gets closer the beast is seen to be at least 9 feet\n";
  cout << "tall, with bright red eyes and white fur. Where there isn't\n";
  cout << "fur the skin is a dark blue.\n";
  cout << "It raises up its massive clawed hands and roars out at the\n";
  cout << "party, Your hero calls out "; 
  cout << "\"Steady friends! We can handle him!\"\n";

  Enemy *boss = new Yeti(0,0,0,200);

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

void MountainPass::map() {
 for(int i=0;i<100;i++){cout<<"\n";}
 cout<<"                                                               \n";
 cout<<" 1)Grotto                                                * * * \n";
 cout<<" 2)Prison                                                * ! * \n";
 cout<<" 3)Swamp                                                 * * * \n";
 cout<<" 4)Mt. Pass (You are here!!!!!!!!!!!!)                     ^   \n";
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
