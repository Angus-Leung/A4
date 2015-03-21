#include "Porc.h"

Porc::Porc() 
{
  id = nextId++;
  space = random(3) + 2;
}

