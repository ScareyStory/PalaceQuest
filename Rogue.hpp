/**************************************************************************
** Program Name: Rogue.hpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the implemntation file for the Rogue class.
**************************************************************************/
#ifndef ROGUE_HPP
#define ROGUE_HPP
#include <iostream>
#include "Character.hpp"

class Rogue : public Character {

private:

protected:

public:

  Rogue(int, int, int, int, int, int, bool, bool);
  
  int attacking();

  int defending();

  void setStrength(int);

  void hp();

  void recover();
};
#endif
