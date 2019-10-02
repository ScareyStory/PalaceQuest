/**************************************************************************
** Program Name: Ruins.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Ruins class.
**************************************************************************/
#ifndef RUINS_HPP
#define RUINS_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Ruins : public Space {

private:

protected:

public:

  Ruins(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
