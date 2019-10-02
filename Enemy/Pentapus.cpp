/***************************************************************************
** Program Name: Pentapus.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Pentapus class
***************************************************************************/
#include <iostream>
#include <random>
#include "Pentapus.hpp"

using std::cout;
using std::endl;

Pentapus::Pentapus(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Pentapus::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  //reseed
  strike = rand();

  strike = strike % 10;

  cout << endl;

  if(strength > 20) {
    cout << "The Pentapus roars an ancient guttaral roar and\n"; 
    cout << "raises its tentacles high above the lake's surface!\n";
  }
  else {
    cout << "The Pentapus's wise eye is lit with terror!\n";
    cout << "Its remaining tentacles rise wearily over the water..\n";
  }

  if(strike < 2) {
    cout << "The Pentapus swings a mighty tentacle... and misses!\n";
    cout << "The ground quakes where the tentacle hits\n";
    attack = 0;
  }

  else if(strike == 9) {
    cout << "The Pentapus swings its tentacles ferociously!\n"; 
    cout << "It's right on target!";
    cout << endl;
    attack = 50;
  }

  else {
    cout << "The Pentapus swings a mighty tentacle... it's on target!";
    cout << endl;
    attack = 40;
  }
}

int Pentapus::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  //reseed
  guard = rand();

  guard = guard % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The Pentapus roars and raises its tentacles in defense!";
    cout << endl;
  }
  else {
    cout <<"The Pentapus readies its guard, but it can't take much more.\n";
  }

  if(guard < 2) {
    cout << "The Pentapus's lets its guard slip!" << endl;
    defense = 0;
  }

  else if(guard == 9) {
    cout << "The Pentapus dives below the surface, taking no damage!";
    cout << endl;
    defense = 1000;
  }

  else {
    cout << "The Pentapus pulls up its guard in time!";
    cout << endl;
    defense = 50;
  }
}

void Pentapus::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0) {
    cout << endl;
    cout << "The Pentapus shrieks out in final anguish!";
    cout << endl;
    cout<<"It sinks deep into the lake, leaving it sanguine and tumultuous";
    cout << endl;
  }
  else { cout << "\nThe Pentapus takes " << damage << " damage\n";}
}

void Pentapus::recover() {}
