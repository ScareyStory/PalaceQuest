/**************************************************************************
** Program Name: Warrior.hpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the implemntation file for the Warrior class.
**************************************************************************/
#ifndef WARRIOR_HPP
#define WARRIOR_HPP
#include <iostream>
#include "Character.hpp"

class Warrior : public Character {

private:

protected:

public:

  Warrior(int, int, int, int, int, int, bool, bool);
  
  int attacking();

  int defending();

  void setStrength(int);

  void hp();

  void recover();
};
#endif
