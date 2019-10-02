/**************************************************************************
** Program Name: Lake.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Lake class.
**************************************************************************/
#ifndef LAKE_HPP
#define LAKE_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Lake : public Space {

private:

protected:

public:

  Lake(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
