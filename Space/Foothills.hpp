/**************************************************************************
** Program Name: Foothills.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Foothills class.
**************************************************************************/
#ifndef FOOTHILLS_HPP
#define FOOTHILLS_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Foothills : public Space {

private:

protected:

public:

  Foothills(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
