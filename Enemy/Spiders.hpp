/***************************************************************************
** Program Name: Spiders.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Spiders class
***************************************************************************/
#ifndef SPIDER_HPP
#define SPIDER_HPP
#include <iostream>
#include "Enemy.hpp"

class Spiders : public Enemy {

private:

protected:

public:

  Spiders(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
