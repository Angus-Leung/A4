#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "BrigManager.h"


int main()
{
  BrigManager manager;

  srand((unsigned)time(0));

  manager.launch();

}

