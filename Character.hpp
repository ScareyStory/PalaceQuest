/**************************************************************************
** Program Name: Character.hpp
** Name:         Story Caplain
** Date:         02/20/19
** Description:  This is the implementation file for the Character class.
**               It is a parent class in the Adventure Game
**************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

class Character {

private:

protected:

  //Character's name
  std::string name;

  //Character attributes
  int type;
  int attack;
  int defense;
  int armor;
  int strength;

  //items
  int  hpot;
  bool weapon;
  bool rstone;


public:

  // constructor sets all attributes
  Character(int, int, int, int, int, int, bool, bool);

  // attacking function gets overridden by character types
  virtual int attacking() = 0;

  // defending functino gets overridden by character types
  virtual int defending() = 0;

  // access name
  std::string getName();
 
  // access character type, for determing actions
  int getType();

  // get character attack value
  int getAttack();

  // get character defense value
  int getDefense();

  // get character armor value
  int getArmor();

  // get character strength value
  int getStrength();

  // set character attack value
  void setAttack(int);

  // set character defense value
  void setDefense(int);

  // set character armor value, returns either zero if armor not broken
  // or returns the excess of damage - armor
  int setArmor(int);

  // each character's setStrength is different because each has a different death
  virtual void setStrength(int) = 0;
  
  // each character has a unique health potion functions because each has a different
  // full health amount
  virtual void hp() = 0;

  // gives basic info about each character
  void info();

  // each character has a different post battle recovery
  virtual void recover() = 0;

  // set name of character
  void setName(bool, std::string);

  // see if character has health potion
  bool hasHpot();

  // give character a health potion
  void giveHpot(int);  

  // check if character has a revive stone
  bool hasRstone();

  // give character a revive stone
  void giveRstone();

  // check if character has a weapon
  bool hasWeapon();

  // give character a weapon
  void giveWeapon();

  // each character has a unique destructor
  virtual ~Character();

};
#endif
