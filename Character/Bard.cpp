/***************************************************************************
** Program Name: Bard.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  This is the cpp file for the Bard class.
***************************************************************************/
#include <iostream>
#include <random>
#include "Bard.hpp"

using std::cout;
using std::endl;

// Constructor initializes character attributes and item amounts
Bard::Bard(int t,int atk,int def,int arm,int str,int h,bool w,bool r) : 
  Character(t, atk, def, arm, str, h, w, r) {}
  
// Bard's implementation of pure virtual function attacking used in battle
int Bard::attacking() {

  // Simulate the rolling of a 20 sided die
  int strike;
  srand(time(NULL));
  strike = rand();
  strike = rand();
  strike = strike % 20;

  cout << endl;
  cout << name << " readies their stringed lute!";

  // If strike is 1-4, bad roll, return a 1 so that the event function knows
  // what level of roll occurred
  if(strike < 4) {
    cout << endl;
    cout << name << " plays a bad melody..." << endl;
    cout << "Team damage is not boosted as much..." << endl;
    return 1;
  }
  // If strike is 15-20, great roll, return a 3 so the event function knows
  // what level of roll occurred
  else if(strike > 15) {
    cout << endl;
    cout << name << " plays a triumphant melody heard for miles!" << endl;
    cout << "Team damage is greatly boosted!" << endl;
    return 3;
  }
  // If strike is 5-15, good roll, return a 2 so the event function knows
  // what level of roll occurred
  else {
    cout << endl;
    cout << name << " plays a battle tune on their lute!" << endl;
    cout << "Team damage is boosted!" << endl;
    return 2;
  }
}

int Bard::defending() {

  // Simulate the rolling of a 20 sided die
  srand(time(NULL));
  int def = rand();
  def = rand();
  def = def % 20;
  
  // If roll is 1 or 2, bad roll, set defense to 10
  if(def < 2) {
    cout << endl;
    cout << name << " trips while blocking!" << endl;
    cout << name << " defends poorly" << endl;
    defense = 10;
  }

  // If roll is 15-20, great roll, set defense to 1000
  else if(def > 15) {
    cout << endl;
    cout << name << " leaps out of the way perfectly!" << endl;
    defense = 1000;
  }

  // If roll is 3-14, good roll, set defense to 30
  else {
    cout << endl;
    cout << name << " blocks some of their opponent's damage!" << endl;
    defense = 30;
  }
  return 1;
}

// To change the health of the bard
void Bard::setStrength(int damage) {

  // Reduce strength by damage dealt
  strength -= damage;

  // If no health remaining and no revive stone, bard is dead
  if(strength <= 0 && rstone == false) {
    strength = 0;
    cout << endl;
    cout << name << " drops to the ground with a fatal wound!\n";
  }

  // If no health remaining but carrying revive stone, bard is revived
  else if(strength <= 0 && rstone == true) {
    strength = 70;
    cout << endl;
    cout << name <<" is revived from their fatal wound!\n";
    rstone = false;
  }

  // If above zero health after damage, continue
  else {
    cout << name << " takes " << damage << " damage\n";
  }
}

// Makes Bard drink a health potion
void Bard::hp() {

  // If Bard holds a potion, drink it
  if(hpot>0) {
    cout << endl;
    cout << name << " drinks a health potion and returns to full strength!";
    cout << endl;
    strength = 70;
    hpot--;
  }

  // If no potion tell user
  else {
    cout << endl;
    cout << name << " is not carrying a health potion!";
    cout << endl;
  }
}

// Recover function gives Bard some armor post battle
void Bard::recover() {

  cout << endl;
  cout << name << " fixes their leather tunic, restoring armor";
  armor = 5;

}
