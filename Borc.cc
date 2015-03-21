#include "Borc.h"

Borc::Borc() 
{
  id = nextId++;
  space = random(3) + 5;
}

