//******************************************************************************************
//Program: othello.h
//
//Author: Marcus McKinley
//Email: mm443615@ohio.edu
//
//Lab Section: cs 2401 (John Dolan)
//
//Description: header file for othello class
//
//Date: December 5, 2017
//
//*******************************************************************************************

#include <iostream>
#include "piece.cc"
#include "game.h"
#include <queue>
#include <string>

namespace main_savitch_14{

class othello : public game
{
  public:
    //int ROWS = 8;
    //int COLUMNS = 8;
    othello();
  protected:
    game* clone() const;
    void compute_moves(std::queue<std::string>& moves) const;
    void display_status() const;
    int evaluate() const;
    bool is_game_over() const;
    bool is_legal(const std::string& move) const;
    void make_move(const std::string& move);
    void restart();
  private:
    piece data[8][8];
    int skip=0;
};

}









