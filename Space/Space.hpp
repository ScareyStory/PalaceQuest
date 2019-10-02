/***************************************************************************
** Program Name: Space.hpp
** Name:         Story Caplain
** Date:         03/08/19
** Description:  This is the header file for the Space class
***************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Enemy.hpp"

using std::vector;

struct Container;

class Space {

private:

protected:

  //Represent item pickups
  int healpot;
  int rstone;
  int battleaxe;
  int bow;
  int staff;

  //For checking if event has happened
  bool check;

public:

  //each int is an item type^^, bool is for check
  Space(int,int,int,int,int,bool);

  //Point to other spaces
  Space *north;
  Space *west;
  Space *east;
  Space *south;

  //To give info about space
  virtual void info() = 0;

  //To move in spaces
  virtual char move(int&, vector<Character*>&) = 0;

  //Event function
  virtual void event(vector<Character*>&) = 0;

  //Check if event has happened
  bool checker();

  //Prints map of space
  virtual void map() = 0;

  //Deletes all spaces
  virtual ~Space();

  friend Container;

};

struct Container {

  //Points to current space
  Space *current;

  //Instantiate space pointers
  Space *space1;
  Space *space2;
  Space *space3;
  Space *space4;

  Space *space5;
  Space *space5s;
  
  Space *space6;
  Space *space6s;
  
  Space *space7;
  Space *space7s;
  
  Space *space8;
  Space *space9;
  Space *space10;

  //Create map with constructor
  Container();

  //Delete map
  ~Container();

};
#endif
