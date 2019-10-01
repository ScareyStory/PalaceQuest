/***************************************************************************
** Program Name: Warden.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Warden class
***************************************************************************/
#include <iostream>
#include <random>
#include "Warden.hpp"

using std::cout;
using std::endl;

Warden::Warden(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Warden::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  //reseed
  strike = rand();

  strike = strike % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The warden laughs and charges, club overhead!\n";
  }
  else {
    cout << "The warden spits up blood and wipes his mouth shakily.\n";
    cout << "He wearily readies his club, his evil grin now a grimace...\n";
  }

  if(strike < 2) {
    cout << "The warden swings his club... and misses!" << endl;
    attack = 0;
  }

  else if(strike == 9) {
    cout << "The warden swings his club ferociously! It's right on target!";
    cout << endl;
    attack = 50;
  }

  else {
    cout << "The warden swings his club... it's on target!";
    cout << endl;
    attack = 40;
  }
}

int Warden::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  //reseed
  guard = rand();

  guard = guard % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The warden laughs heartily and raises his club in defense!\n";
  }
  else {
    cout << "The warden defeatedly pulls up his club in defense.\n";
  }

  if(guard < 2) {
    cout << "The warden's completely misses his block!" << endl;
    defense = 0;
  }

  else if(guard == 9) {
    cout << "The warden blocks and sidesteps perfectly, taking no damage!";
    cout << endl;
    defense = 1000;
  }

  else {
    cout << "The warden pulls up his block in time!";
    cout << endl;
    defense = 50;
  }
}

void Warden::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0) {
    cout << endl;
    cout << "The team's strikes completely overwhelm the Warden!!!";
    cout << endl;
    cout << "The warden stumbles backwards and falls into a pile of webs";
    cout << endl;
    cout << "As he does a colony of small spiders converge on him, ";
    cout << endl;
    cout << "ensuring his demise. As they feast, one spider, larger than  ";
    cout << endl;
    cout << "the rest scurries away with purpose. Your hero feels";
    cout << endl;
    cout << "that this will have consequences later on...\n";
  }
  else { 
    cout << "\nThe warden takes " << damage << " damage\n";
    cout << "Warden Health: "<<strength<<"/100\n";
  }
}

void Warden::recover() {}
