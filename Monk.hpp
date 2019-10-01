/**************************************************************************
** Program Name: Monk.hpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the implemntation file for the Monk class.
**************************************************************************/
#ifndef MONK_HPP
#define MONK_HPP
#include <iostream>
#include "Character.hpp"

class Monk : public Character {

private:

protected:

public:

  Monk(int, int, int, int, int, int, bool, bool);
  
  int attacking();

  int defending();

  void setStrength(int);

  void hp();

  void recover();
};
#endif
