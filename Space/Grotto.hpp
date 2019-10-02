/**************************************************************************
** Program Name: Grotto.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Grotto class.
**************************************************************************/
#ifndef GROTTO_HPP
#define GROTTO_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Grotto : public Space {

private:

protected:

public:

  Grotto(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
