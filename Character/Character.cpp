/**************************************************************************
** Program Name: Character.cpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the .cpp file for the Character class.
**************************************************************************/
#include <iostream>
#include "Character.hpp"
#include "Warrior.hpp"
#include "Rogue.hpp"
#include "Mage.hpp"
#include "Monk.hpp"
#include "Bard.hpp"

using std::cout;
using std::endl;

// Character constructor initalizes type, attack, defense, armor, strength, health
// weapon, revive stone
Character::Character(int t, int atk, int def, int arm, int str, int h, 
  bool w, bool r) : type(t), attack(atk), defense(def), armor(arm), 
  strength(str), hpot(h), weapon(w), rstone(r) {}

// Accessor function for name
std::string Character::getName() { return name; }

// Mutator function for name
// each non player character type has a default name
void Character::setName(bool isPlayer, std::string n) {

  // If the player's name is being set, use their input
  if(isPlayer==true) {
    name = n;
  }
  // Else if character is an NPC give default name
  else {
    switch(type) {
      case 1: name = "Kronk the Warrior";break;
      case 2: name = "Eden the Rogue";break;
      case 3: name = "Gustaf the Mage";break;
      case 4: name = "Zen the Monk";break;
      case 5: name = "Horatio the Bard";break;
    }
  }
}
// Accessor function for type
int Character::getType() { return type; }

// Accessor function for attack value
int Character::getAttack() { return attack; }

// Mutator function for attack value
void Character::setAttack(int a) { attack = a; }

// Accessor function for defense value
int Character::getDefense() { return defense; }

// Mutator function for defense value
void Character::setDefense(int d) {defense = d;}

// Check if character has weapon
bool Character::hasWeapon() { return weapon; }

// Set weapon boolean to true
void Character::giveWeapon() {weapon = true;}

// Accessor function for armor value
int Character::getArmor() { return armor; }

// Mutator function for armor value
int Character::setArmor(int damage) { 
 
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

// Accessor function for character health
int Character::getStrength() { return strength; }

// Gives information about character
void Character::info() {

  cout << endl;
  cout << name << "\n_______________\n";

  switch(type) {
    case 1: cout << "Warrior\n";break;
    case 2: cout << "Rogue\n";break;
    case 3: cout << "Mage\n";break;
    case 4: cout << "Monk\n";break;
    case 5: cout << "Bard\n";break;
    default: cout << "ERROR\n";
  }

  cout << "Health: " << strength << endl;
  cout << "Armor: " << armor << endl;
  cout << "Potions: " << hpot << endl;
  cout << "Carrying weapon: " << bool(weapon) << endl;
  cout << "Carrying revive stone: " << bool(rstone) << endl;
  cout << endl;
}

// Check if character has a health potion
bool Character::hasHpot() {
  if(hpot > 0) {return true;}
  else{return false;}
}

// Give character a health potion
void Character::giveHpot(int p) {hpot += p;}

// Check if revive stone boolean is true
bool Character::hasRstone() {return rstone;}

// Set revive stone boolean to true
void Character::giveRstone() {rstone=true;}

Character::~Character() {}
