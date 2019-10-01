/***************************************************************************
** Program Name: Yeti.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Yeti class
***************************************************************************/
#include <iostream>
#include <random>
#include "Yeti.hpp"

using std::cout;
using std::endl;

Yeti::Yeti(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Yeti::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  //reseed
  strike = rand();

  strike = strike % 10;

  cout << endl;

  if(strength > 20) {
    cout << "The Yeti roars and slams its fists into the ground!\n\n";
  }
  else {
    cout << "The Yeti's roar cracks into a whimper.\n";
    cout << "Its white fur is stained dark with blood, but it fights on!\n";
  }

  if(strike < 2) {
    cout << "The Yeti swings its claws... and misses!" << endl;
    attack = 0;
  }

  else if(strike == 9) {
    cout << "The Yeti swings its claws ferociously! It's right on target!";
    cout << endl;
    attack = 50;
  }

  else {
    cout << "The Yeti swings its claws... it's on target!";
    cout << endl;
    attack = 40;
  }
}

int Yeti::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  //reseed
  guard = rand();

  guard = guard % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The Yeti roars deeply and raises its arms in defense!\n\n";
  }
  else {
    cout << "The Yeti pulls up its guard, but it cannot take much more.\n";
  }

  if(guard < 2) {
    cout << "The Yeti's completely misses its block!" << endl;
    defense = 0;
  }

  else if(guard == 9) {
    cout << "The Yeti blocks and sidesteps perfectly, taking no damage!";
    cout << endl;
    defense = 1000;
  }

  else {
    cout << "The Yeti pulls up its block in time!";
    cout << endl;
    defense = 50;
  }
}

void Yeti::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0) {
    cout << endl;
    cout << "The Yeti runs away from battle hemorrhaging blood";
    cout << endl;
    cout << "It makes it only a few yards before collapsing in the snow";
    cout << endl;
    cout << "The party walks up to the beast and delivers a killing blow\n\n";
  }
  else { 
    cout << "\nThe Yeti takes " << damage << " damage\n";
    cout << "Yeti health: "<<strength<<"/200\n";
  }
}

void Yeti::recover() {}
