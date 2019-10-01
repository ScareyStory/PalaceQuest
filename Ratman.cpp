/***************************************************************************
** Program Name: Ratman.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Ratman class
***************************************************************************/
#include <iostream>
#include <random>
#include "Ratman.hpp"

using std::cout;
using std::endl;

Ratman::Ratman(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Ratman::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  //reseed
  strike = rand();

  strike = strike % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The Ratman screeches, claws and fangs at the ready!!";
  }
  else {
    cout << "The Ratman chitters painfully, blood dripping from its\n";
    cout << "chipped fangs...\n";
  }

  if(strike < 2) {
    cout << "The Ratman swings its claws... and misses!" << endl;
    attack = 0;
  }

  else if(strike == 9) {
    cout << "The Ratman charges ferociously! It's right on target!";
    cout << endl;
    attack = 50;
  }

  else {
    cout << "The Ratman swings its claws... it's on target!";
    cout << endl;
    attack = 40;
  }
}

int Ratman::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  //reseed
  guard = rand();

  guard = guard % 10;

  cout << endl;

  if(strength > 10) {
    cout << "The Ratman pounces back ready to defend!" << endl;
  }
  else {
    cout << "The Ratman stumbles back, eyes wide and guard up.\n";
  }

  if(guard < 2) {
    cout << "The Ratman's completely misses its block!" << endl;
    defense = 0;
  }

  else if(guard == 9) {
    cout << "The Ratman pounces aside perfectly, taking no damage!";
    cout << endl;
    defense = 1000;
  }

  else {
    cout << "The Ratman blocks in time, taking only some damage!";
    cout << endl;
    defense = 50;
  }
}

void Ratman::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0) {
    cout << endl;
    cout << "The Ratman, blinded in both eyes from combat, screams out!";
    cout << endl;
    cout << "It charges blindly out of the hut, and heads Southwards.";
    cout << endl;
    cout << "Your hero decides to let it flee, there is nothing but death";
    cout << endl;
    cout << "to the south of these lands.";
    cout << "\n\n";
  }
  else { cout << "\nThe Ratman takes " << damage << " damage\n";}
}

void Ratman::recover() {}
