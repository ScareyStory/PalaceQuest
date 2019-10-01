/***************************************************************************
** Program Name: Monk.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  This is the cpp file for the Monk class.
***************************************************************************/
#include <iostream>
#include <random>
#include "Monk.hpp"

using std::cout;
using std::endl;

Monk::Monk(int t,int atk,int def,int arm,int str,int h,bool w,bool r) : 
  Character(t, atk, def, arm, str, h, w, r) {}
  
int Monk::attacking() {

  int strike;

  if(weapon==true) {

    srand(time(NULL));
    strike = rand();

    strike = rand();

    strike = strike % 20;

    cout << endl;
    cout << name << " readies their staff, it is humming with energy!";

    if(strike < 4) {
      cout << endl;
      cout << name << "'s attack misses!" << endl;
      attack = 0;
    }
    else if(strike > 18) {
      cout << endl;
      cout << name << " sends a massive blast of energy!!!!" << endl;
      attack = 250;
    }
    else {
      cout << endl;
      cout << name << "'s strike lands true!" << endl;
      attack = 50;
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
      cout << name << "'s attack misses!" << endl;
      attack = 0;
    }
    else if(strike > 15) {
      cout << endl;
      cout << name << " sends a massive blast of energy!!!!" << endl;
      attack = 250;
    }
    else {
      cout << endl;
      cout << name << "'s strike lands true!" << endl;
      attack = 40;
    }

  }
  return 0;
}

int Monk::defending() {

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
    cout << name << " lands a perfect parry!" << endl;
    defense = 1000;
  }
  else {
    cout << endl;
    cout << name << " defends well, reducing damage!" << endl;
    defense = 30;
  }
  return 0;
}

void Monk::setStrength(int damage) {

  strength -= damage;

  if(strength <= 0 && rstone == false) {
    strength = 0;
    cout << endl;
    cout << name << " drops to the ground with a fatal wound!\n";
  }
  else if(strength <= 0 && rstone == true) {
    strength = 70;
    cout << endl;
    cout << name <<" is revived from their fatal wound!\n";
    rstone = false;
  }
  else {
    cout << name << " takes " << damage << " damage\n";
  }
}

void Monk::hp() {

  if(hpot>0) {
    cout << endl;
    cout << name << " drinks a health potion and returns to full strength!";
    cout << endl;
    strength = 70;
    hpot--;
  }
  else {
    cout << endl;
    cout << name << " is not carrying a health potion!";
    cout << endl;
  }
}

void Monk::recover() {

  cout << endl;
  cout << name << " brushes dirt from their robes after the battle.";

}
