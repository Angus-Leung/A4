#ifndef CARRAY_H
#define CARRAY_H

#include "Cell.h"
#include "Pirate.h"

class CArray
{
  public:
    CArray();
    ~CArray();
    int   getSize();
    Cell* get(int);
    int   add(Cell*);
  private:
    int    size;
    Cell*  elements[MAX_CELLS];
};

#endif
