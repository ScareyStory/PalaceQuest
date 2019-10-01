/***************************************************************************
** Program Name: Warrior.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  This is the cpp file for the Warrior class.
***************************************************************************/
#include <iostream>
#include <random>
#include "Warrior.hpp"

using std::cout;
using std::endl;

Warrior::Warrior(int t, int atk, int def, int arm, int str, int h,
  bool w, bool r) : Character(t, atk, def, arm, str, h, w, r) {}
  
int Warrior::attacking() {

  int strike;

  if(weapon==true) {

    srand(time(NULL));
    strike = rand();

    strike = rand();

    strike = strike % 20;

    cout << endl;
    cout << name << " readies their mighty battleaxe!";

    if(strike < 4) {
      cout << endl;
      cout << name << "'s attack missed!" << endl;
      attack = 0;
    }
    else if(strike > 15) {
      cout << endl;
      cout << name << " lands a critical hit!" << endl;
      attack = 45;
    }
    else {
      cout << endl;
      cout << name << "'s strike lands true!" << endl;
      attack = 30;
    }
  }
  else {

    srand(time(NULL));
    strike = rand();

    strike = rand();

    strike = strike % 20;

    cout << endl;
    cout << name << " is weaponless and must fight barehanded!";

    if(strike < 4) {
      cout << endl;
      cout << name << "'s attack missed!" << endl;
      attack = 0;
    }
    else if(strike > 15) {
      cout << endl;
      cout << name << " lands a critical hit!" << endl;
      attack = 20;
    }
    else {
      cout << endl;
      cout << name << "'s strike lands true!" << endl;
      attack = 10;
    }

  }
  return 0;
}

int Warrior::defending() {

  srand(time(NULL));
  int def = rand();

  def = rand();

  def = def % 20;
  
  if(def < 2) {
    cout << endl;
    cout << name << " trips while blocking!" << endl;
    cout << name << " defends poorly" << endl;
    defense = 10;
  }

  else if(def > 15) {
    cout << endl;
    cout << name << " counters perfectly!" << endl;
    defense = 1000;
  }
  else {
    cout << endl;
    cout << name << " blocks well, driving off some damage!" << endl;
    defense = 30;
  }
  return 0;
}

void Warrior::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0 && rstone == false) {
    strength = 0;
    cout << endl;
    cout << name << " drops to the ground with a fatal wound!\n";
  }
  else if(strength <= 0 && rstone == true) {
    strength = 80;
    cout << endl;
    cout << name <<" is revived from their fatal wound!\n";
    rstone = false;
  }
  else {
    cout << name << " takes " << damage << " damage\n";
  }
}

void Warrior::hp() {

  if(hpot>0) {
    cout << endl;
    cout << name << " drinks a health potion and returns to full strength!";
    cout << endl;
    hpot--;
    strength = 80;
  }
  else {
    cout << endl;
    cout << name << " is not carrying a health potion!";
    cout << endl;
  }
}

void Warrior::recover() {

  cout << endl;
  cout << name << " fixes their heavy armor, restoring it fully.";
  armor = 20;

}
