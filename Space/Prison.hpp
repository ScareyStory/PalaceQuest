/**************************************************************************
** Program Name: Prison.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the Prison class.
**************************************************************************/
#ifndef PRISON_HPP
#define PRISON_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class Prison : public Space {

private:

protected:

public:

  Prison(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
