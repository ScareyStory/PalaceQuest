/***************************************************************************
** Program Name: Yeti.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Yeti class
***************************************************************************/
#ifndef YETI_HPP
#define YETI_HPP
#include <iostream>
#include "Enemy.hpp"

class Yeti : public Enemy {

private:

protected:

public:

  Yeti(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
