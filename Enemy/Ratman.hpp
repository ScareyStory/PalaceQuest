/***************************************************************************
** Program Name: Ratman.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Ratman class
***************************************************************************/
#ifndef RATMAN_HPP
#define RATMAN_HPP
#include <iostream>
#include "Enemy.hpp"

class Ratman : public Enemy {

private:

protected:

public:

  Ratman(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
