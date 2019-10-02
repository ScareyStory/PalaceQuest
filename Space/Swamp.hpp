/**************************************************************************
** Program Name: Swamp.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Swamp class.
**************************************************************************/
#ifndef SWAMP_HPP
#define SWAMP_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Swamp : public Space {

private:

protected:

public:

  Swamp(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
