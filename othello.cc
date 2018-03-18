//******************************************************************************************
//Program: othello.cc
//
//Author: Marcus McKinley
//Email: mm443615@ohio.edu
//
//Lab Section: cs 2401 (John Dolan)
//
//Description: implementation file for othello class
//
//Date: December 5, 2017
//
//*******************************************************************************************

#include <iostream>
#include "othello.h"
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
namespace main_savitch_14 {


othello::othello()
{
  restart();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void othello::restart()
{
 for (int y=0;y<8;y++)
  {
    for (int x=0;x<8;x++)
    {
      data[x][y].make_neutral();
      
    }
  }
  data[3][3].make_white();
  data[3][4].make_black();
  data[4][3].make_black();
  data[4][4].make_white();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void othello::display_status()const
{
  queue<string> x;
  compute_moves(x);
  
  std::cout<<std::endl;
  std::cout<<"************************************************"<<std::endl;
  std::cout<<"*  DIRECTIONS: PUT LETTER FIRST THEN NUMBER!!! *"<<std::endl;
  std::cout<<"************************************************"<<std::endl<<std::endl;
  std::cout<<"Available Moves:"<<endl;
  while(!x.empty()){cout<<x.front()<<" "; x.pop();}
  std::cout<<endl<<endl;
  std::cout<<"   A   B   C   D   E   F   G   H"<<std::endl;
  std::cout<<' '<<'|';
  for (int i=0;i<7;i++)
  {
    std::cout<<'*'<<'*'<<'*'<<'|';
  }
  std::cout<<'*'<<'*'<<'*'<<'|'<<std::endl;
  
  for(int i=0;i<7;i++)
  {
    std::cout<<i+1;
    for(int m=0;m<8;m++)
    {
      
      std::cout<<'|'<<" "<<data[i][m]<<" ";                                              
    }
    std::cout<<'|'<<std::endl;                    
    std::cout<<' '<<'|';
    for(int n=0;n<7;n++)
    {
      std::cout<<'*'<<'*'<<'*'<<'|';
    }
    std::cout<<'*'<<'*'<<'*'<<'|'<<std::endl;
  }
  std::cout<<'8';
  for(int i=0;i<8;i++)
  {
    std::cout<<'|'<<" "<<data[7][i]<<" ";                           
  }
  std::cout<<'|'<<std::endl;
  std::cout<<' '<<'*';
  for(int m=0;m<7;m++)
  {
    std::cout<<'*'<<'*'<<'*'<<'*';
  }
  std::cout<<'*'<<'*'<<'*'<<'*'<<std::endl;
  std::cout<<"                                                     Board by Marcus McKinley"<<std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void othello::make_move(const std::string& move)                                             
{  											   
  queue<string> q;
  compute_moves(q);
  if(q.front()=="$$M$$")
  {
    game::make_move("car");
    skip++;
    return;
  }
                                                                                           //   A   B   C   D   E   F   G   H
                                                                                	   // |***|***|***|***|***|***|***|***|
  char letter,number;                                                                      //1|00 |01 |02 |03 |04 |05 |06 |07 |
  int column,row;                                                   	                   // |***|***|***|***|***|***|***|***|
  letter=toupper(move[0]);  //letter c                                   	           //2|10 |11 |12 |13 |14 |15 |16 |17 |
  number=move[1];  //number r                                            	           // |***|***|***|***|***|***|***|***|
  row=letter-65;                                                                           //3|20 |21 |22 |23 |W  |b  |26 |27 |
  column=number-49;                                                                        // |***|***|***|***|***|***|***|***|
  piece tmp;                                                                               //4|30 |31 |32 |W  |b  |35 |36 |37 |
  if(last_mover()==COMPUTER){data[column][row].make_white();}                              // |***|***|***|***|***|***|***|***|
  if(last_mover()==HUMAN){data[column][row].make_black();}                                 //5|40 |41 |42 |w  |W  |45 |46 |47 |
  //white pieces                                                                           // |***|***|***|***|***|***|***|***|
  int i=0,r=0;                                                                             //6|50 |51 |52 |w  |54 |55 |56 |57 |
                                                                                           // |***|***|***|***|***|***|***|***|
  if(data[column][row].is_white())                                                         //7|60 |61 |62 |63 |64 |65 |66 |67 |
  {                                                                                        // |***|***|***|***|***|***|***|***|
    //south                                                                                //8|70 |71 |72 |73 |74 |75 |76 |77 |
                                                                                           // *********************************
    for( i=column+1;data[i][row].is_black();i++){if(i<0||i>7){break;}}                                                                                
      if(data[i][row].is_white())
      {                          
        for(int m=i-1;m!=column;m--)
        {
          data[m][row].make_white();
        }
      }                                                                                                     
                                                                                                                       
    //north                                                                           
    for( i=column-1;data[i][row].is_black();i--){if(i<0||i>7){break;}}                                                                                 
      if(data[i][row].is_white())
      {
        for(int m=i+1;m!=column;m++)
        {
          data[m][row].make_white();                                       
        }                                                           
      }								      
    //northeast                                                                       
    for( r=column-1,i=row+1;data[r][i].is_black();r--,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r+1,n=i-1;m!=column;m++,n--)
        {
          data[m][n].make_white();
        }
      }

    //northwest
    for(r=column-1,i=row-1;data[r][i].is_black();r--,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r+1,n=i+1;m!=column;m++,n++)
        {
          data[m][n].make_white();
        }
      }
 
    //southeast
    for(r=column+1,i=row+1;data[r][i].is_black();r++,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r-1,n=i-1;m!=column;m--,n--)
        {
          data[m][n].make_white();
        }
      }
 
    //southwest
    for(r=column+1,i=row-1;data[r][i].is_black();r++,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r-1,n=i+1;m!=column;m--,n++)
        {
          data[m][n].make_white();
        }
      } 

    //east
    for(i=row+1;data[column][i].is_black();i++){if(i<0||i>7){break;}}
      if(data[column][i].is_white())
      {
        for(int m=i-1;m!=row;m--)
        {
          data[column][m].make_white();
        }
      }

    //west
    for(i=row-1;data[column][i].is_black();i--){if(i<0||i>7){break;}}
      if(data[column][i].is_white())
      {
        for(int m=i+1;m!=row;m++)
        {
          data[column][m].make_white();
        }
      }
  }
  
  //black pieces                                                                           
  if(data[column][row].is_black())                                                         
  {                                                                                   
    //south
    //int i;                                                                          
    for(i=column+1;data[i][row].is_white();i++){if(i<0||i>7){break;}}                                                                                
      if(data[i][row].is_black())
      {
        for(int m=i-1;m!=column;m--)
        {
          data[m][row].make_black();
        }
      }                                                                                                     
                                                                                                                                                                          
    //north                                                                           
    for(i=column-1;data[i][row].is_white();i--){if(i<0||i>7){break;}}                                                                                 
      if(data[i][row].is_black())
      {
        for(int m=i+1;m!=column;m++)
        {
          data[m][row].make_black();                                       
        }                                                           
      }	
								      
    //northeast                                                                       
    for(r=column-1,i=row+1;data[r][i].is_white();r--,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r+1,n=i-1;m!=column;m++,n--)
        {
          data[m][n].make_black();
        }
      }

    //northwest
    for(r=column-1,i=row-1;data[r][i].is_white();r--,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r+1,n=i+1;m!=column;m++,n++)
        {
          data[m][n].make_black();
        }
      }
 
    //southeast
    for(r=column+1,i=row+1;data[r][i].is_white();r++,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r-1,n=i-1;m!=column;m--,n--)
        {
          data[m][n].make_black();
        }
      }
 
    //southwest
    for(r=column+1,i=row-1;data[r][i].is_white();r++,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r-1,n=i+1;m!=column;m--,n++)
        {
          data[m][n].make_black();
        }
      } 

    //east
    for(i=row+1;data[column][i].is_white();i++){if(i<0||i>7){break;}}
      if(data[column][i].is_black())
      {
        for(int m=i-1;m!=row;m--)
        {
          data[column][m].make_black();
        }
      }

    //west
    for(i=row-1;data[column][i].is_white();i--){if(i<0||i>7){break;}}
      if(data[column][i].is_black())
      {
        for(int m=i+1;m!=row;m++)
        {
          data[column][m].make_black();
        }                                                                 //MAKE MOVE
      }
  }
  game::make_move(" ");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool othello::is_legal(const std::string& move) const
{       
  if(move=="$$M$$")
  {
    return true;
  }                                                                                   //c+1 r-1 = southwest
  char letter,number;                                                                      //c   r-1 = west
  int column,row;                                                   	                   //c+1 r   = south
  letter=toupper(move[0]);  //letter c                                   	           //c+1 r+1 = southeast
  number=move[1];  //number r                                            	           //c   r+1 = east
  row=letter-65;                                                                           //c-1 r   = north
  column=number-49;                                                                        //c-1 r-1 = northwest
  piece tmp;                                                                               //c-1 r+1 = northeast
  if(last_mover()==COMPUTER){tmp.make_white();}                                   
  if(last_mover()==HUMAN){tmp.make_black();}

  //off the board
  if(row>7||row<0||column>7||column<0){return false;}
  
  //Already taken
  if(data[column][row].is_black()||data[column][row].is_white()){return false;}
                                                                                       
  //white pieces  
                  int i=0,r=0;                                                         // ********************************* 
  if(tmp.is_white())                                                         
  {                                                                                   
    //south
                                                                              
    for( i=column+1;data[i][row].is_black();i++){if(i<0||i>7){break;}}                                                                                
      if(data[i][row].is_white())
      {
        for(int m=i-1;m!=column;m--)
        {
          return true;
        }
      }                                                                                                     
                                                                                                                                                                          
    //north                                                                           
    for( i=column-1;data[i][row].is_black();i--){if(i<0||i>7){break;}}                                                                                 
      if(data[i][row].is_white())
      {
        for(int m=i+1;m!=column;m++)
        {
          return true;                                       
        }                                                           
      }								      
    //northeast                                                                       
    for( r=column-1,i=row+1;data[r][i].is_black();r--,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r+1,n=i-1;m!=column;m++,n--)
        {
          return true;
        }
      }

    //northwest
    for(r=column-1,i=row-1;data[r][i].is_black();r--,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r+1,n=i+1;m!=column;m++,n++)
        {
          return true;
        }
      }
 
    //southeast
    for(r=column+1,i=row+1;data[r][i].is_black();r++,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r-1,n=i-1;m!=column;m--,n--)
        {
          return true;
        }
      }
 
    //southwest
    for(r=column+1,i=row-1;data[r][i].is_black();r++,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_white())
      {
        for(int m=r-1,n=i+1;m!=column;m--,n++)
        {
          return true;
        }
      } 

    //east
    for(i=row+1;data[column][i].is_black();i++){if(i<0||i>7){break;}}
      if(data[column][i].is_white())
      {
        for(int m=i-1;m!=row;m--)
        {
          return true;
        }
      }

    //west
    for(i=row-1;data[column][i].is_black();i--){if(i<0||i>7){break;}}
      if(data[column][i].is_white())
      {
        for(int m=i+1;m!=row;m++)
        {
          return true;
        }
      }
  }
  
  //black pieces                                                                           
  if(tmp.is_black())                                                         
  {                                                                                   
    //south
    //int i;                                                                          
    for(i=column+1;data[i][row].is_white();i++){if(i<0||i>7){break;}}                                                                                
      if(data[i][row].is_black())
      {
        for(int m=i-1;m!=column;m--)
        {
          return true;
        }
      }                                                                                                     
                                                                                                                                                                          
    //north                                                                           
    for(i=column-1;data[i][row].is_white();i--){if(i<0||i>7){break;}}                                                                                 
      if(data[i][row].is_black())
      {
        for(int m=i+1;m!=column;m++)
        {
          return true;                                       
        }                                                           
      }	
								      
    //northeast                                                                       
    for(r=column-1,i=row+1;data[r][i].is_white();r--,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r+1,n=i-1;m!=column;m++,n--)
        {
          return true;
        }
      }

    //northwest
    for(r=column-1,i=row-1;data[r][i].is_white();r--,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r+1,n=i+1;m!=column;m++,n++)
        {
          return true;
        }
      }
 
    //southeast
    for(r=column+1,i=row+1;data[r][i].is_white();r++,i++){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r-1,n=i-1;m!=column;m--,n--)
        {
          return true;
        }
      }
 
    //southwest
    for(r=column+1,i=row-1;data[r][i].is_white();r++,i--){if(i<0||r<0||r>7||i>7){break;}}
      if(data[r][i].is_black())
      {
        for(int m=r-1,n=i+1;m!=column;m--,n++)
        {
          return true;
        }
      } 

    //east
    for(i=row+1;data[column][i].is_white();i++){if(i<0||i>7){break;}}
      if(data[column][i].is_black())
      {
        for(int m=i-1;m!=row;m--)
        {
          return true;
        }
      }

    //west
    for(i=row-1;data[column][i].is_white();i--){if(i<0||i>7){break;}}
      if(data[column][i].is_black())
      {
        for(int m=i+1;m!=row;m++)
        {
          return true;
        }                                                                 //MAKE MOVE
      }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void othello::compute_moves(std::queue<std::string>& moves) const
{
  string move="  ";
  for(char i='1';i<'9';i++)
  {
    for(char m='A';m<'I';m++)
    {      
      move[0]=m;
      move[1]=i;   
      if(is_legal(move))
      {
        moves.push(move);
      }                                            
    }    
  }
  if(moves.empty())
  {
    moves.push("$$M$$");   
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int othello::evaluate() const
{
  int white=0,black=0;
  for(int i=0;i<8;i++)
  {
    for(int m=0;m<8;m++)
    {
      if(data[i][m].is_white()){white=white+1;}
      if(data[i][m].is_black()){black=black+1;}
    }
  }
  return(black-white);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
game* othello::clone() const
{
  return(new othello(*this));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool othello::is_game_over() const
{
  if(skip>1){return true;}
}
}


