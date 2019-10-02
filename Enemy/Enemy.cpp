/**************************************************************************
** Program Name: Enemy.cpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the .cpp file for the Enemy class.
**************************************************************************/
#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(int atk, int def, int arm, int str) : 
  attack(atk), defense(def), armor(arm), strength(str) {}

int Enemy::getAttack() { return attack; }

void Enemy::setAttack(int a) { attack = a; }


int Enemy::getDefense() { return defense; }

void Enemy::setDefense(int d) {defense = d;}


int Enemy::getArmor() { return armor; }

int Enemy::setArmor(int damage) { 
 
  //If attack doesn't destroy armor, reduce armor 
  if(armor >= damage) {
    armor -= damage;
    return 0;
  }
  //Else if attack destroys armor, or no armor, return damage
  //to be deducted from strength
  else {
    int excess = damage - armor;
    armor = 0;
    return excess;
  }
}

int Enemy::getStrength() { return strength; }

Enemy::~Enemy() {}
