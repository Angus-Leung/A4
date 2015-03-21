#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

UImanager::UImanager() { }

/*   Function:  mainMenu                         				*/
/*         in:  Location of int that will be modified to		*/
/*				the menu choice									*/
/*        out:  Modified int representing the chosen menu		*/
/*				option								           	*/
/*    Purpose:  Display the main menu of the BMS				*/

void UImanager::mainMenu(int* choice)
{
    string str;

    *choice = -1;

#ifndef TEST_MODE
    system("clear");
#endif

    cout<< "\n\n\n                   WELCOME TO THE BRIG MANAGEMENT SYSTEM \n\n";
    cout << "( 1 )  Manage pirates" << endl;
    cout << "( 2 )  View brig" << endl;
    cout << "( 0 )  Exit" << endl;

    while (*choice < 0 || *choice > 2) {
        cout << "Enter your selection:  ";
        getline(cin, str);
        stringstream ss(str);
        ss >> *choice;
    }
}

/*   Function:  pirateMenu                         				*/
/*         in:  Location of int that will be modified to		*/
/*				the menu choice									*/
/*        out:  Modified int representing the chosen menu		*/
/*				option								           	*/
/*    Purpose:  Display the pirate management menu				*/

void UImanager::pirateMenu(int* choice)
{
    string str;

    *choice = -1;

#ifndef TEST_MODE
    system("clear");
#endif

    cout<< "\n\n\n                   PIRATE MANAGEMENT MENU \n\n";
    cout << "( 1 )  Add pirates" << endl;
    cout << "( 2 )  Remove pirate" << endl;
    cout << "( 0 )  Exit" << endl;

    while (*choice < 0 || *choice > 2) {
        cout << "Enter your selection:  ";
        getline(cin, str);
        stringstream ss(str);
        ss >> *choice;
    }
}

/*   Function:  gettNumPirates                         		    */
/*         in:  Location of int that will be modified to		*/
/*				the number of pirates requested					*/
/*        out:  Modified int representing the chosen number		*/
/*				of pirates										*/
/*    Purpose:  Prompts the user for the number of pirates		*/
/*				they wish to enter into the system				*/

void UImanager::getNumPirates(int* numPirates)
{
    string    str;

    cout << endl << "Enter the number of pirates:   ";
    getline(cin, str);
    stringstream ss1(str);
    ss1 >> *numPirates;
}

/*   Function:  getIdToRemove                         		    */
/*         in:  Location of int that will be modified to		*/
/*				the pirate ID requested					        */
/*        out:  Modified int representing the requested ID      */
/*    Purpose:  Prompts the user for the ID of the pirate       */
/*              that they want removed from the brig            */

void UImanager::getIdToRemove(int* pId){
    
    string    str;
    
    cout << endl << "Enter the ID of the pirate to remove:   ";
    getline(cin, str);
    stringstream ss1(str);
    ss1 >> *pId;
    
}

/*   Function:  printBrig                         				*/
/*         in:  Location of Brig to be printed					*/
/*    Purpose:  Display the cells currently in the brig and		*/
/*				the pirates in each cell by copying the queue   */
/*              contained in each cell into a temporary queue,  */
/*              printing the data of the front of the queue,    */
/*              popping the front of the queue, and repeating   */
/*              until empty                                     */


void UImanager::printBrig(Brig* brig)
{
    CArray& cells = brig->getCells();
    Queue* tempQueue;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Brig: #cells=" << cells.getSize() <<endl;

    for (int i=0; i<cells.getSize(); ++i) {
        cout << "--Cell "<<i<<": space remaining="<<cells.get(i)->getSpace()<<endl;
        tempQueue = new Queue(cells.get(i)->getPirates());
        while (!(tempQueue->empty())) {
            cout <<"----Pirate id: "<< tempQueue->front()->getId() 
                << "  space: " << tempQueue->front()->getSpace() << endl;
            tempQueue->pop();
        }
        delete tempQueue;
    }
}

/*   Function:  showError                         		        */
/*         in:  Error to be displayed                           */
/*    Purpose:  Display an error and wait for user to press	    */
/*				enter											*/

void UImanager::showError(string err)
{
    cout << err << " -- press enter to continue...";
    cin.get();
}

/*   Function:  pause                         					*/
/*    Purpose:  Display a message and wait for user to press	*/
/*				enter											*/

void UImanager::pause()
{
    string str;

    cout << endl << "\nPress enter to continue...";
    getline(cin, str);
}

