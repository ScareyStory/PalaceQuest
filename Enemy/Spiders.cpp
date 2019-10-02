/***************************************************************************
** Program Name: Spiders.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Spiders class
***************************************************************************/
#include <iostream>
#include <random>
#include "Spiders.hpp"

using std::cout;
using std::endl;

Spiders::Spiders(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Spiders::attacking() {

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
    cout << "The two remaining spiders scurry forward, fangs at the ready!";

    strike1 = rand();
    strike2 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;

    strike = strike1 + strike2;

    if(strike < 7) {
      cout << "\nThe spiders both lunge... and miss!\n";
      attack = 0;
    }
    else if(strike > 15) {
      cout << "\nThe spiders rush in, chittering ferociously!\n";
      attack = 50;
    }
    else {
      cout << "\nBoth spiders lunge... they're on target!\n";
      attack = 40;
    }
  }
  else if(strength > 40) {
    cout << endl;
    cout << "The three spiders attack, fangs dripping with venom!\n";

    strike1 = rand();
    strike2 = rand();
    strike3 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;
    strike3 = strike3 % 10 + 1;

    strike = strike1 + strike2 + strike3;

    if(strike < 8) {
      cout << "\nThe three spiders lunge... and miss!\n";
      attack = 0;
    }
    else if(strike > 25) {
      cout << "\nThe spiders rush in, chittering ferociously!\n";
      attack = 55;
    }
    else {
      cout << "\nThe three spiders lunge... they're on target!\n";
      attack = 45;
    }
  }
  else {
    cout << endl;
    cout << "The last spider charges!\n";
  
    strike1 = rand();

    strike1 = strike1 % 10 + 1;

    strike = strike1;

    if(strike < 3) {
      cout << "\nThe spider lunges... and misses!\n";
      attack = 0;
    }
    else if(strike > 8) {
      cout << "\nThe spider rushes in, chittering ferociously!\n";
      attack = 45;
    }
    else {
      cout << "\nThe spider lunges... its on target!\n";
      attack = 40;
    }
  }
}

int Spiders::defending() {

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
    cout << "The two remaining spiders dig in to defend!";

    guard1 = rand();
    guard2 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;

    guard = guard1 + guard2;

    if(guard < 7) {
      cout << "\nThe spiders both miss their dodge!\n";
      defense = 0;
    }
    else if(guard > 15) {
      cout << "\nThe spiders both dodge perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nBoth spiders miss their dodge but block well!\n";
      defense = 70;
    }
  }
  else if(strength > 40) {
    cout << endl;
    cout << "The three spiders dig in to defend!\n";

    guard1 = rand();
    guard2 = rand();
    guard3 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;
    guard3 = guard3 % 10 + 1;

    guard = guard1 + guard2 + guard3;

    if(guard < 8) {
      cout << "\nThe three spiders both miss their dodge!\n";
      defense = 0;
    }
    else if(guard > 25) {
      cout << "\nThe spiders dodge perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe three spiders miss their dodges but block well!\n";
      defense = 80;
    }
  }
  else {
    cout << endl;
    cout << "The last spider readies his defense!\n";
  
    guard1 = rand();

    guard1 = guard1 % 10 + 1;

    guard = guard1;

    if(guard < 5) {
      cout << "\nThe spider misses its dodge!\n";
      defense = 0;
    }
    else if(guard > 9) {
      cout << "\nThe spider dodgees perfectly!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe spider misses its dodge but blocks well!\n";
      defense = 60;
    }
  }
}

void Spiders::setStrength(int damage) {

  strength -= damage;

  if(strength > 40) {
    cout << endl;
    cout << "The spiders take " << damage << " damage, but all 3 remain";
    cout << endl;
  }
  else if(strength <= 40 && strength > 20) {
    cout << endl;
    cout << "The spiders take " << damage << " damage, only 2 remain";
    cout << endl;
  }
  else if(strength <= 20 && strength > 0) {
    cout << endl;
    cout << "The spiders take " << damage << " damage, only 1 remains";
    cout << endl;
  }
  else { 
    cout << "\nThe last spider falls to its back, legs curled...";
    cout << endl;
    cout << "The forest is finally free from their reign of terror\n";
    cout << "...but your hero's journey is far from over\n";
  }
}

void Spiders::recover() {}
