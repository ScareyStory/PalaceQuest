/**************************************************************************
** Program Name: Darkness.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Darkness class.
**************************************************************************/
#ifndef DARKNESS_HPP
#define DARKNESS_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Darkness : public Space {

private:

protected:

public:

  Darkness(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
