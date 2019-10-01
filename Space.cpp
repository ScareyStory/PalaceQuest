/***************************************************************************
** Program Name: Space.cpp
** Name:         Story Caplain
** Date:         03/08/19
** Description:  This is the cpp file for Space class and Container struct
***************************************************************************/
#include <iostream>
#include "Space.hpp"
#include "Grotto.hpp"
#include "Prison.hpp"
#include "Swamp.hpp"
#include "MountainPass.hpp"
#include "Foothills.hpp"
#include "Hut.hpp"
#include "CursedValley.hpp"
#include "HiddenCrypt.hpp"
#include "Forest.hpp"
#include "Shrine.hpp"
#include "Ruins.hpp"
#include "Lake.hpp"
#include "Darkness.hpp"

Space::Space(int hp, int rs, int ba, int b, int s, bool c) :
  healpot(hp), rstone(rs), battleaxe(ba), bow(b), staff(s), check(c) {}

//True means event still needs to happen, false means it already did
bool Space::checker() {
  if(check==true) {check=false;return true;}
  else {return check;}
}

Space::~Space(){}

//Create map with constructor
Container::Container() {

  space1  = new Grotto(0,0,0,0,0,false);
  
  space2  = new Prison(3,0,1,1,1,true);
  
  space3  = new Swamp(0,0,0,0,1,false);
  
  space4  = new MountainPass(0,1,0,0,0,true);
 
  space5  = new Foothills(0,0,0,0,0,false);
  
  space5s = new Hut(3,0,0,0,0,true);

  space6  = new CursedValley(0,0,0,0,0,true);
  
  space6s = new HiddenCrypt(1,1,0,0,0,true);
  
  space7  = new Forest(0,0,0,0,0,true);
  
  space7s = new Shrine(1,1,0,0,0,true);
  
  space8  = new Ruins(0,0,0,0,0,true);
  
  space9  = new Lake(0,0,0,0,0,true);
  
  space10 = new Darkness(0,0,0,0,0,true);

  current = space1;

  //Grotto
  //Set Space1's pointers
  space1->north = NULL;
  space1->west  = NULL;
  space1->east  = space2;
  space1->south = NULL;

  //Prison
  //Set Space2's pointers
  space2->north = NULL;
  space2->west  = NULL;
  space2->east  = space3;
  space2->south = NULL;

  //Swamp
  //Set Space3's pointers
  space3->north = NULL;
  space3->west  = space2;
  space3->east  = space4;
  space3->south = space5;

  //Mt. Pass
  //Set Space4's pointers
  space4->north = NULL;
  space4->west  = space3;
  space4->east  = space6;
  space4->south = NULL;

  //Foothills
  //Set Space5's pointers
  space5->north = NULL;
  space5->west  = space3;
  space5->east  = space6;
  space5->south = space5s;

  //Hut
  //Set Space5s's pointers
  space5s->north = space5;
  space5s->west  = NULL;
  space5s->east  = NULL;
  space5s->south = NULL;

  //Cursed Valley
  //Set Space6's pointers
  space6->north = space6s;
  space6->west  = space4;
  space6->east  = space7;
  space6->south = space5;

  //Hidden Crypt
  //Set Space6s's pointers
  space6s->north = NULL;
  space6s->west  = NULL;
  space6s->east  = NULL;
  space6s->south = space6;

  //Forest
  //Set Space7's pointers
  space7->north = space8;
  space7->west  = space6;
  space7->east  = NULL;
  space7->south = space7s;

  //Shrine
  //Set Space7s's pointers
  space7s->north = space7;
  space7s->west  = NULL;
  space7s->east  = NULL;
  space7s->south = NULL;

  //Ruins
  //Set Space8's pointers
  space8->north = space9;
  space8->west  = NULL;
  space8->east  = NULL;
  space8->south = space7;

  //Lake
  //Set Space9's pointers
  space9->north = space10;
  space9->west  = NULL;
  space9->east  = NULL;
  space9->south = space8;

  //Heart of Darkness
  //Set Space10's pointers
  space10->north = NULL;
  space10->west  = NULL;
  space10->east  = NULL;
  space10->south = space9;

}
//Delete map
Container::~Container() {

  delete space1;
  delete space2;
  delete space3;
  delete space4;
  delete space5;
  delete space5s;
  delete space6;
  delete space6s;
  delete space7;
  delete space7s;
  delete space8;
  delete space9;
  delete space10;

}
