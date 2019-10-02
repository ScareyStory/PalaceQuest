/***************************************************************************
** Program Name: Nightsprites.cpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  cpp file for the Nightsprites class
***************************************************************************/
#include <iostream>
#include <random>
#include "Nightsprites.hpp"

using std::cout;
using std::endl;

Nightsprites::Nightsprites(int atk, int def, int arm, int str) : 
  Enemy(atk,def,arm,str){}


int Nightsprites::attacking() {

  int strike;

  //seed
  srand(time(NULL));
  strike = rand();

  int strike1 = rand();
  int strike2 = rand();
  int strike3 = rand();
  int strike4 = rand();
  int strike5 = rand();
  
  cout << endl;

  if(strength > 120) {
    cout << endl;
    cout << "All 5 nightsprites float forward, humming with energy!";

    strike1 = rand();
    strike2 = rand();
    strike3 = rand();
    strike4 = rand();
    strike5 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;
    strike3 = strike3 % 10 + 1;
    strike4 = strike4 % 10 + 1;
    strike5 = strike5 % 10 + 1;

    strike = strike1 + strike2 + strike3 + strike4 + strike5;

    if(strike < 12) {
      cout << "\nThe nightsprites zap with dark energy... and miss!\n";
      attack = 0;
    }
    else if(strike > 43) {
      cout << "\nThe nightsprites rush in...\n"; 
      cout << "their blasts louder than lightning!\n";
      attack = 55;
    }
    else {
      cout << "\nThe nightsprites zap with dark energy..."; 
      cout << "\nthey're on target!\n";
      attack = 45;
    }
  }
  else if(strength > 90 && strength <= 120) {
    cout << endl;
    cout << "The 4 remaining nightsprites float forward," 
         << "humming with energy!";

    strike1 = rand();
    strike2 = rand();
    strike3 = rand();
    strike4 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;
    strike3 = strike3 % 10 + 1;
    strike4 = strike4 % 10 + 1;

    strike = strike1 + strike2 + strike3 + strike4;

    if(strike < 12) {
      cout << "\nThe nightsprites zap with dark energy... and miss!\n";
      attack = 0;
    }
    else if(strike > 43) {
      cout << "\nThe nightsprites rush in...\n"; 
      cout << "their blasts louder than lightning!\n";
      attack = 50;
    }
    else {
      cout << "\nThe nightsprites zap with dark energy..."; 
      cout << "\nthey're on target!\n";
      attack = 40;
    }
  }
  else if(strength > 60 && strength <= 90) {
    cout << endl;
    cout << "The 3 remaining nightsprites float forward," 
         << "humming with energy!";

    strike1 = rand();
    strike2 = rand();
    strike3 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;
    strike3 = strike3 % 10 + 1;

    strike = strike1 + strike2 + strike3;

    if(strike < 12) {
      cout << "\nThe nightsprites zap with dark energy... and miss!\n";
      attack = 0;
    }
    else if(strike > 43) {
      cout << "\nThe nightsprites rush in...\n"; 
      cout << "their blasts louder than lightning!\n";
      attack = 45;
    }
    else {
      cout << "\nThe nightsprites zap with dark energy..."; 
      cout << "\nthey're on target!\n";
      attack = 35;
    }
  }
  else if(strength > 30 && strength <= 60) {
    cout << endl;
    cout << "The 2 remaining nightsprites float forward," 
         << "humming with energy!";

    strike1 = rand();
    strike2 = rand();

    strike1 = strike1 % 10 + 1;
    strike2 = strike2 % 10 + 1;

    strike = strike1 + strike2;

    if(strike < 12) {
      cout << "\nThe nightsprites zap with dark energy... and miss!\n";
      attack = 0;
    }
    else if(strike > 43) {
      cout << "\nThe nightsprites rush in...\n"; 
      cout << "their blasts louder than lightning!\n";
      attack = 40;
    }
    else {
      cout << "\nThe nightsprites zap with dark energy..."; 
      cout << "\nthey're on target!\n";
      attack = 30;
    }
  }
  else {
    cout << endl;
    cout << "The last remaining nightsprite floats forward," 
         << "humming with energy!";

    strike1 = rand();

    strike1 = strike1 % 10 + 1;

    strike = strike1;

    if(strike < 12) {
      cout << "\nThe nightsprites zaps with dark energy... and misses!\n";
      attack = 0;
    }
    else if(strike > 43) {
      cout << "\nThe nightsprite rushes in...\n"; 
      cout << "its blasts louder than lightning!\n";
      attack = 35;
    }
    else {
      cout << "\nThe nightsprite zaps with dark energy..."; 
      cout << "\nits on target!\n";
      attack = 25;
    }
  }
}

int Nightsprites::defending() {

  int guard;

  //seed
  srand(time(NULL));
  guard = rand();

  int guard1 = rand();
  int guard2 = rand();
  int guard3 = rand();
  int guard4 = rand();
  int guard5 = rand();
  
  cout << endl;

  if(strength > 120) {
    cout << endl;
    cout << "All 5 nightsprites float back, linking together in defense!";

    guard1 = rand();
    guard2 = rand();
    guard3 = rand();
    guard4 = rand();
    guard5 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;
    guard3 = guard3 % 10 + 1;
    guard4 = guard4 % 10 + 1;
    guard5 = guard5 % 10 + 1;

    guard = guard1 + guard2 + guard3 + guard4 + guard5;

    if(guard < 12) {
      cout << "\nThe nightsprites fail to pull up their electric guard!\n";
      defense = 0;
    }
    else if(guard > 43) {
      cout << "\nThe nightsprites pull up their guard!\n"; 
      cout << "their guard is perfect and unbreakable!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe nightsprites pull up their guard..."; 
      cout << "\nIt is strong but not perfect!\n";
      defense = 70;
    }
  }
  else if(strength > 90 && strength <= 120) {
    cout << endl;
    cout << "The 4 remaining nightsprites float back,"; 
    cout << "linking together in defense!";

    guard1 = rand();
    guard2 = rand();
    guard3 = rand();
    guard4 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;
    guard3 = guard3 % 10 + 1;
    guard4 = guard4 % 10 + 1;

    guard = guard1 + guard2 + guard3 + guard4;

    if(guard < 10) {
      cout << "\nThe nightsprites fail to pull up their electric guard!\n";
      defense = 0;
    }
    else if(guard > 35) {
      cout << "\nThe nightsprites pull up their guard!\n"; 
      cout << "their guard is perfect and unbreakable!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe nightsprites pull up their guard..."; 
      cout << "\nIt is strong but not perfect!\n";
      defense = 60;
    }
  }
  else if(strength > 60 && strength <= 90) {
    cout << endl;
    cout << "The 3 remaining nightsprites float back,"; 
    cout << "linking together in defense!";

    guard1 = rand();
    guard2 = rand();
    guard3 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;
    guard3 = guard3 % 10 + 1;

    guard = guard1 + guard2 + guard3;

    if(guard < 10) {
      cout << "\nThe nightsprites fail to pull up their electric guard!\n";
      defense = 0;
    }
    else if(guard > 26) {
      cout << "\nThe nightsprites pull up their guard!\n"; 
      cout << "their guard is perfect and unbreakable!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe nightsprites pull up their guard..."; 
      cout << "\nIt is strong but not perfect!\n";
      defense = 50;
    }
  }
  else if(strength > 30 && strength <= 60) {
    cout << endl;
    cout << "The 2 remaining nightsprites float back,"; 
    cout << "linking together in defense!";

    guard1 = rand();
    guard2 = rand();

    guard1 = guard1 % 10 + 1;
    guard2 = guard2 % 10 + 1;

    guard = guard1 + guard2;

    if(guard < 6) {
      cout << "\nThe nightsprites fail to pull up their electric guard!\n";
      defense = 0;
    }
    else if(guard > 18) {
      cout << "\nThe nightsprites pull up their guard!\n"; 
      cout << "their guard is perfect and unbreakable!\n";
      defense = 1000;
    }
    else {
      cout << "\nThe nightsprites pull up their guard..."; 
      cout << "\nIt is strong but not perfect!\n";
      defense = 40;
    }
  }
  else {
    cout << endl;
    cout << "The last remaining nightsprite floats back," 
         << "it cannot defend alone!";
    defense = 0;
  }
}

void Nightsprites::setStrength(int damage) {

  strength -= damage;

  if(strength > 120) {
    cout << endl;
    cout << "The nightsprites take "<<damage<<" damage, but all 5 remain";
    cout << endl;
  }
  else if(strength <= 120 && strength > 90) {
    cout << endl;
    cout << "The nightsprites take "<<damage<<" damage, only 4 remain";
    cout << endl;
  }
  else if(strength <= 90 && strength > 60) {
    cout << endl;
    cout << "The nightsprites take "<<damage<<" damage, only 3 remain";
    cout << endl;
  }
  else if(strength <= 60 && strength > 30) {
    cout << endl;
    cout << "The nightsprites take "<<damage<<" damage, only 2 remain";
    cout << endl;
  }
  else if(strength <= 30 && strength > 0) {
    cout << endl;
    cout << "The nightsprites take "<<damage<<" damage, only 1 remains";
    cout << endl;
  }
  else { 
    cout << "\nThe last Nightsprite explodes in a blast of energy!\n";
    cout << endl;
  }
}

void Nightsprites::recover() {}
