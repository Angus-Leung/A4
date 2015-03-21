#include <iostream>
#include "BrigManager.h"

using namespace std;

BrigManager::BrigManager()
{
    view = new UImanager;
    brig = new Brig;
}

BrigManager::~BrigManager()
{
    delete view;
    delete brig;
}

/*   Function:  launch                               			*/
/*    Purpose:  Control object of the program.              	*/
/*				Loops through the main menu and pirate 			*/
/*				management menu by calling Display functions,	*/
/*				and calls the add/remove Pirate and printBrig	*/
/*				functions when the user asks for it.			*/

void BrigManager::launch()
{
    int    choice1 = -1;
    int    choice2 = -1;
    int    id      = -1;
    int    rc;

    while (choice1 != 0) {
        view->mainMenu(&choice1);
        if (choice1 == 0) {
            break;
        }
        else if (choice1 == 1) {
            choice2 = -1;
            while (choice2 != 0) {
                view->pirateMenu(&choice2);
                if (choice2 == 0) {
                    break;
                }
                else if (choice2 == 1) {
                    int num;
                    view->getNumPirates(&num);
                    addPirates(num);
                }
                else if (choice2 == 2) {
                    int pId;
                    view->getIdToRemove(&pId);
                    brig->removePirate(pId);
                }
            }
        }
        else if (choice1 == 2) {
            view->printBrig(brig);
        }
        if (choice2 != 0)
            view->pause();
    }
}

/*   Function:  addPirates		                         		*/
/*    Purpose:  Adds a user-decided number of pirates to		*/
/*				the brig										*/

void BrigManager::addPirates(int numPirates)
{
    Pirate*   newPirate;
    
    while (numPirates > 0) {
        newPirate = new Pirate;
        brig->addPirate(newPirate);
        --numPirates;
    }
}
