/***************************************************************************
** Program Name: Skellybones.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Skellybones class
***************************************************************************/
#include <iostream>
#include <random>
#include "Skellybones.hpp"

using std::cout;
using std::endl;

Skellybones::Skellybones(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Skellybones::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  int strike1 = rand();
  int strike2 = rand();
  int strike3 = rand();
  
  cout << endl;

  if(strength > 20 && strength <= 40 ) {
    cout << endl;
    cout << "The two remaining skeletons run forward, swords at the ready!";

    strike1 = rand();
    strike2 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;

    strike = strike1 + strike2;

    if(strike < 7) {
      cout << "\nThe skeletons both swing... and miss!\n";
      attack = 0;
    }
    else if(strike > 15) {
      cout << "\nThe skeletons rush in, striking ferociously!\n";
      attack = 50;
    }
    else {
      cout << "\nBoth skeletons swing... they're on target!\n";
      attack = 40;
    }
  }
  else if(strength > 40) {
    cout << endl;
    cout << "The three skeletons charge, bones clacking!\n";

    strike1 = rand();
    strike2 = rand();
    strike3 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;
    strike3 = strike3 % 10 + 1;

    strike = strike1 + strike2 + strike3;

    if(strike < 8) {
      cout << "\nThe three skeletons swing... and miss!\n";
      attack = 0;
    }
    else if(strike > 25) {
      cout << "\nThe skeletons rush in, striking ferociously!\n";
      attack = 55;
    }
    else {
      cout << "\nThe three skeletons swing... they're on target!\n";
      attack = 45;
    }
  }
  else {
    cout << endl;
    cout << "The last skeleton charges!\n";
  
    strike1 = rand();

    strike1 = strike1 % 10 + 1;

    strike = strike1;

    if(strike < 3) {
      cout << "\nThe skeleton swings... and misses!\n";
      attack = 0;
    }
    else if(strike > 8) {
      cout << "\nThe skeleton rushes in, striking ferociously!\n";
      attack = 45;
    }
    else {
      cout << "\nThe skeleton swings... its on target!\n";
      attack = 40;
    }
  }
}

int Skellybones::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  int guard1 = rand();
  int guard2 = rand();
  int guard3 = rand();
  
  cout << endl;

  if(strength > 20 && strength <= 40 ) {
    cout << endl;
    cout << "The two remaining skeletons prepare to defend!";

    guard1 = rand();
    guard2 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;

    guard = guard1 + guard2;

    if(guard < 7) {
      cout << "\nThe skeletons both miss their block!\n";
      defense = 0;
    }
    else if(guard > 15) {
      cout << "\nThe skeletons both parry perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nBoth skeletons block well!\n";
      defense = 70;
    }
  }
  else if(strength > 40) {
    cout << endl;
    cout << "The three skeletons get in defense position!\n";

    guard1 = rand();
    guard2 = rand();
    guard3 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;
    guard3 = guard3 % 10 + 1;

    guard = guard1 + guard2 + guard3;

    if(guard < 8) {
      cout << "\nThe three skeletons both miss their block!\n";
      defense = 0;
    }
    else if(guard > 25) {
      cout << "\nThe skeletons parry perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe three skeletons block well!\n";
      defense = 80;
    }
  }
  else {
    cout << endl;
    cout << "The last skeleton readies his defense!\n";
  
    guard1 = rand();

    guard1 = guard1 % 10 + 1;

    guard = guard1;

    if(guard < 5) {
      cout << "\nThe skeleton misses its block\n";
      defense = 0;
    }
    else if(guard > 9) {
      cout << "\nThe skeleton parries perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe skeleton blocks well!\n";
      defense = 60;
    }
  }
}

void Skellybones::setStrength(int damage) {

  strength -= damage;

  if(strength > 40) {
    cout << endl;
    cout << "The skeletons take " << damage << " damage, but all 3 remain";
    cout << endl;
  }
  else if(strength <= 40 && strength > 20) {
    cout << endl;
    cout << "The skeletons take " << damage << " damage, only 2 remain";
    cout << endl;
  }
  else if(strength <= 20 && strength > 0) {
    cout << endl;
    cout << "The skeletons take " << damage << " damage, only 1 remains";
    cout << endl;
  }
  else { 
    cout << "\n" <<
      "The last skeleton shatters on impact, all that remains is bones...";
    cout << endl;
  }
}

void Skellybones::recover() {}
