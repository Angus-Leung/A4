#include "Brig.h"

Brig::Brig() { }

Brig::~Brig() {
    // Deletes the data contained in each queue in each cell
	for (int i=0; i<cells.getSize(); ++i) {
		cells.get(i)->getPirates().deleteData();
	}
}

/*   Function:  addPirate	                         		    */
/*         in:  Location of pirate to be added to the brig		*/
/*    Purpose:  Adds a single pirate to the brig in a cell		*/
/*				that has enough space for it					*/

int Brig::addPirate(Pirate* pirate)
{
    Cell* newCell;
    int index = -1;
    int rc;

    for (int i=0; i<cells.getSize(); ++i) {
        if (cells.get(i)->fits(pirate)) 
            index = i;
    }

    if (index >= 0) {
        rc = cells.get(index)->getPirates().push(pirate);
        if (rc != C_OK)
            return C_NOK;
        cells.get(index)->reduceSpace(pirate->getSpace());
    }
    else {
        newCell = new Cell;
        cells.add(newCell);
        rc = newCell->getPirates().push(pirate);
        if (rc != C_OK)
            return C_NOK;
        newCell->reduceSpace(pirate->getSpace());
    }
    return C_OK;
}

/*   Function:  overloaded addition assignment operator         */
/*         in:  Location of pirate to be added to the brig		*/
/*    Purpose:  Adds a single pirate to the brig in a cell		*/
/*				that has enough space for it					*/

Brig& Brig::operator+=(Pirate* pirate)
{
    Cell* newCell;
    int index = -1;

    for (int i=0; i<cells.getSize(); ++i) {
        if (cells[i]->fits(pirate)) 
            index = i;
    }

    if (index >= 0) {
        cells[index]->getPirates() += pirate;
        *(cells[index]) -= pirate->getSpace();
    }
    else {
        newCell = new Cell;
        cells += newCell;
        cell->getPirates() += pirate;
        *newCell -= pirate->getSpace();
    }
    return *this;
}

/*   Function:  addPirate	                         		    */
/*         in:  ID of pirate to be removed from the brig		*/
/*    Purpose:  Removes a pirate with a matching ID from the    */
/*              brig                                            */

int Brig::removePirate(int pirateId) {
    Cell* currCell;
    Pirate* foundPirate;
    for (int i=0; i<cells.getSize(); ++i) {
        currCell = cells[i];
        // goes through each Queue and asks if it contains the Pirate to be removed
        foundPirate = currCell->getPirates().find(pirateId);
        if (foundPirate != 0) {
            *currCell+=(currCell->getPirates().getPirateSpace(pirateId));
            currCell->getPirates() -= foundPirate;  // remove it from the Queue
            delete foundPirate;                       // deallocate the data
            return C_OK;
        } 
    }
    return C_NOK;   // if we've reached this then the Pirate wasn't found
}

CArray& Brig::getCells() { return cells; }

