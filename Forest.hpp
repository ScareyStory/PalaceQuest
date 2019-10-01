/**************************************************************************
** Program Name: Forest.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Forest class.
**************************************************************************/
#ifndef FOREST_HPP
#define FOREST_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Forest : public Space {

private:

protected:

public:

  Forest(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
