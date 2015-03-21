#include "Pirate.h"

int Pirate::nextId = 1001;

Pirate::Pirate() 
{
  id = nextId++;
  space = random(4) + 2;
}

int Pirate::getId()    { return id; }
int Pirate::getSpace() { return space; }

