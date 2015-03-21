#include <iostream>
#include <string>
using namespace std;

#include "CArray.h"

CArray::CArray() : size(0)
{ 
  for (int i=0; i<MAX_CELLS; ++i)
    elements[i] = 0;
}

CArray::~CArray() 
{
  for (int i=0; i<size; ++i)
    delete elements[i];
}

int CArray::getSize() { return size; }

Cell* CArray::get(int index)
{
  if (index >= 0 && index < size)
    return elements[index];

  return 0;
}

int CArray::add(Cell* cell)
{
  if (size == MAX_CELLS)
    return C_NOK;

  elements[size] = cell;
  size++;
  return C_OK;
}

