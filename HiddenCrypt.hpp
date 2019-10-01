/**************************************************************************
** Program Name: HiddenCrypt.hpp
** Name:         Story Caplain
** Date:         03/09/19
** Description:  This is the implementation file for the HiddenCrypt class.
**************************************************************************/
#ifndef HIDDENCRYPT_HPP
#define HIDDENCRYPT_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Space.hpp"

class HiddenCrypt : public Space {

private:

protected:

public:

  HiddenCrypt(int,int,int,int,int,bool);

  void info();

  char move(int&, std::vector<Character*>&);

  void event(std::vector<Character *>&);

  void map();

};
#endif
