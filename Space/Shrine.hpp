/**************************************************************************
** Program Name: Shrine.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Shrine class.
**************************************************************************/
#ifndef SHRINE_HPP
#define SHRINE_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Shrine : public Space {

private:

protected:

public:

  Shrine(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
