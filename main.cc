//******************************************************************************************
//Program: testmain.cc
//
//Author: Marcus McKinley
//Email: mm443615@ohio.edu
//
//Lab Section: cs 2401 (John Dolan)
//
//Description: Plays one move othello
//
//Date: December 5, 2017
//
//*******************************************************************************************

#include "othello.h"
#include "game.h"
//#include "piece.h"
#include <iostream>
using namespace main_savitch_14;
using namespace std;
int main()
{
  /*cout<<(char)205;
  piece mar;
  mar.make_white();
  cout<<mar;*/






  othello me;
  me.play();

  game::who winner;
  winner=me.play();
  if(winner==game::HUMAN){cout<<"COMPUTER WINS"<<endl;}
  if(winner==game::COMPUTER){cout<<"YOU WIN"<<endl;}
  
  int i;
  cin>>i;
}
