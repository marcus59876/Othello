//******************************************************************************************
//Program: piece.h
//
//Author: Marcus McKinley
//Email: mm443615@ohio.edu
//
//Lab Section: cs 2401 (John Dolan)
//
//Description: header file for piece class
//
//Date: December 5, 2017
//
//*******************************************************************************************

#include <iostream>
#include "colors.h"
class piece
{
  public:
    piece(){neutral=true;} 
    piece(bool a, bool b, bool c){black=a;white=b;neutral=c;}
    void flip()
    {
      if(black){make_white();}
      else if(white){make_black();}
    }
    bool is_black()const
    {
      if(black){return true;}
      else{return false;}
    }
    bool is_white()const
    {
      if(white){return true;}
      else{return false;}
    }
    bool is_neutral()const
    {
      if(neutral){return true;}
      else{return false;}
    }
    bool is_opposite(piece x)
    {
      if(black&&x.is_white()){return true;}
      if(white&&x.is_black()){return true;}
    } 
    void make_neutral(){neutral=true;black=false;white=false;}
    void make_black(){black=true;white=false;neutral=false;}
    void make_white(){white=true;black=false;neutral=false;}

    void output(std::ostream& x)
    {
      if(black){x<<B_BLACK<<" "<<RESET;}
      if(white){x<<B_WHITE<<" "<<RESET;}
      if(neutral){x<<' ';}
    }

    friend std::ostream& operator<<(std::ostream& x, piece p)
    {
      p.output(x);
      return(x);
    }


  protected:
  private:
    bool black, white,neutral;
  
};


 
