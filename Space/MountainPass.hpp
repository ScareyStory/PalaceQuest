/**************************************************************************
** Program Name: MountainPass.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the MountainPass class.
**************************************************************************/
#ifndef MOUNTAINPASS_HPP
#define MOUNTAINPASS_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class MountainPass : public Space {

private:

protected:

public:

  MountainPass(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
