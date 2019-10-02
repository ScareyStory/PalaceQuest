/***************************************************************************
** Program Name: Skellybones.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Skellybones class
***************************************************************************/
#ifndef SKELLYBONES_HPP
#define SKELLYBONES_HPP
#include <iostream>
#include "Enemy.hpp"

class Skellybones : public Enemy {

private:

protected:

public:

  Skellybones(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
