/***************************************************************************
** Program Name: Evil.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Evil class
***************************************************************************/
#ifndef EVIL_HPP
#define EVIL_HPP
#include <iostream>
#include "Enemy.hpp"

class Evil : public Enemy {

private:

protected:

public:

  Evil(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
