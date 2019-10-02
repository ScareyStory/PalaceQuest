/**************************************************************************
** Program Name: Bard.hpp
** Name:         Story Caplain
** Date:         03/07/19
** Description:  This is the implemntation file for the Bard class.
**************************************************************************/
#ifndef BARD_HPP
#define BARD_HPP
#include <iostream>
#include "Character.hpp"

class Bard : public Character {

private:

protected:

public:

  Bard(int, int, int, int, int, int, bool, bool);
  
  int attacking();

  int defending();

  void setStrength(int);

  void hp();

  void recover();
};
#endif
