/***************************************************************************
** Program Name: Pentapus.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Pentapus class
***************************************************************************/
#ifndef PENTAPUS_HPP
#define PENTAPUS_HPP
#include <iostream>
#include "Enemy.hpp"

class Pentapus : public Enemy {

private:

protected:

public:

  Pentapus(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
