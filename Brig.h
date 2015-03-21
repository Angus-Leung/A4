#ifndef BRIG_H
#define BRIG_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"
#include "CArray.h"

class Brig 
{
    public:
        Brig();
        ~Brig();
        int removePirate(int);
        CArray& getCells();
        Brig& operator+=(Pirate*);
    
    private:
        CArray cells;
};

#endif

