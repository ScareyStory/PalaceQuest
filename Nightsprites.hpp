/***************************************************************************
** Program Name: Nightsprites.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Nightsprites class
***************************************************************************/
#ifndef NIGHTSPRITES_HPP
#define NIGHTSPRITES_HPP
#include <iostream>
#include "Enemy.hpp"

class Nightsprites : public Enemy {

private:

protected:

public:

  Nightsprites(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
