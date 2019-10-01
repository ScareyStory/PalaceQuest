/***************************************************************************
** Program Name: Evil.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Evil class
***************************************************************************/
#include <iostream>
#include <random>
#include "Evil.hpp"

using std::cout;
using std::endl;

Evil::Evil(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Evil::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  //reseed
  strike = rand();

  strike = strike % 10;

  cout << endl;

  if(strength > 100) {
    cout << "\nThe Evil's aura drowns the room in anguish!\n";
    cout << "Its power is incredibly strong!\n";
  }
  else {
    cout << "\nThe Evil's power is waning! It looks to be mortal!\n";
  }

  if(strike < 2) {

    cout << "\nA blast of energy from the Evil misses entirely!\n";
    attack = 0;

  }

  else if(strike == 9) {
    cout << "\nThe Evil sends a full charge blast right at your party!\n";
    cout << endl;
    attack = 50;
  }

  else {
    cout << endl;
    cout << "\nThe Evil sends a blast of energy right at your party!\n";
    attack = 40;
  }
}

int Evil::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  //reseed
  guard = rand();

  guard = guard % 10;

  cout << endl;

  if(strength > 30) {
    cout << "The Evil Incarnate shakes the room violently!\n";
    cout << "Its eye is trained on the hero!\n";
  }
  else {
    cout << "The Evil's eye is pulsating red, its aura is losing strength!";
    cout << endl;
  }

  if(guard < 7) {

    cout << "\nThe Evil Incarnate's defensive aura breaks momentarily!\n";
    cout << "It is vulnerable!\n";
    defense = 0;
  }

  else if(guard > 6) {
    cout << "\nThe Evil Incarnate's defensive aura is too strong to break!";
    cout << endl;
    defense = 1000;
  }
}

void Evil::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0) {
    cout << endl;
    cout << "The Evil Incarnate shrieks out as its dealt a fatal blow!\n";
    cout << endl;
    cout << endl;
    cout << "Its shriek grows in volume as the room quakes from the sound";
    cout << endl;
    cout << "As it reaches an unimaginable volume the Evil collapses in on";
    cout << endl;
    cout << "itself, beginning to implode. As it does it begins to suck in";
    cout << endl;
    cout << "all the darkness from the room, and then begins ripping in ";
    cout << endl;
    cout << "the darkness manifesting from it all across the region. The";
    cout << endl;
    cout << "darkness plumes into the palace's windows like thick smoke.";
    cout << endl;
    cout << "And then, just as quickly as it begun, the collapse ended as";
    cout << endl;
    cout << "the last of the darknss rips into the singularity the Evil ";
    cout << endl;
    cout << "disappears into the void and then winks away...";
    cout << endl;
  }
  else { cout << "\nThe Evil takes " << damage << " damage\n";}
}

void Evil::recover() {}
