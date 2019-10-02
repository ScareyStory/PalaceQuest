/**************************************************************************
** Program Name: CursedValley.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the CursedValley class.
**************************************************************************/
#ifndef CURSEDVALLEY_HPP
#define CURSEDVALLEY_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class CursedValley : public Space {

private:

protected:

public:

  CursedValley(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
