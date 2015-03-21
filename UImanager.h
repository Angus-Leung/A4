#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <string>
using namespace std;
#include "Brig.h"

#define TEST_MODE

class UImanager {
  public:
    UImanager();
    void mainMenu(int*);
    void pirateMenu(int*);
    void getNumPirates(int*);
    void printBrig(Brig*);
    void showError(string);
    void pause();
    void getIdToRemove(int* pId);
};

#endif

