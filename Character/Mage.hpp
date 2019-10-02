/**************************************************************************
** Program Name: Mage.hpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the implementation file for the Mage class.
**************************************************************************/
#ifndef MAGE_HPP
#define MAGE_HPP
#include <iostream>
#include "Character.hpp"

class Mage : public Character {

private:

protected:

public:

  Mage(int, int, int, int, int, int, bool, bool);
  
  int attacking();

  int defending();

  void setStrength(int);

  void hp();

  void recover();
};
#endif
