/***************************************************************************
** Program Name: Warden.hpp
** Name:         Story Caplain
** Date:         03/11/19
** Description:  Header file for the Warden class
***************************************************************************/
#ifndef WARDEN_HPP
#define WARDEN_HPP
#include <iostream>
#include "Enemy.hpp"

class Warden : public Enemy {

private:

protected:

public:

  Warden(int, int, int, int);

  int attacking();

  int defending();

  void setStrength(int);

  void recover();

};
#endif
