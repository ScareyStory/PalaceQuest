/**************************************************************************
** Program Name: Enemy.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  This is the implemntation file for the Enemy class.
**************************************************************************/
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy {

private:

protected:

  //Enemy attributes
  int attack;
  int defense;
  int armor;
  int strength;

public:

  Enemy(int, int, int, int);

  virtual int attacking() = 0;

  virtual int defending() = 0;

  int getAttack();

  int getDefense();

  int getArmor();

  int getStrength();

  void setAttack(int);

  void setDefense(int);

  int setArmor(int);

  virtual void setStrength(int) = 0;

  virtual void recover() = 0;

  virtual ~Enemy();

};
#endif
