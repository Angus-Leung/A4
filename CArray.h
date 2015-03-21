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
    CArray& operator+=(Cell*);
    Cell*   operator[](int);
    
  private:
    int    size;
    Cell*  elements[MAX_CELLS];
};

#endif
