#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Queue.h"

class Cell 
{
  public:
    Cell(int=MAX_CELL_SPACE);
    bool    fits(Pirate*);
    Queue&  getPirates();
    int     getSpace();
    void    reduceSpace(int);
    void    increaseSpace(int);
    Cell&   operator+=(int);
    Cell&   operator-=(int);
    Cell&   operator+=(Pirate*);
    
  private:
    static int  nextId;
    int         cellNumber;
    int         spaceRemaining;
    Queue       pirates;
};

#endif

