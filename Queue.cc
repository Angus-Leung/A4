#include "Queue.h"


//Default constructor
Queue::Queue() : head(0){
    
    
}

//Copy constructor
Queue::Queue(Queue &origQueue) {
	head = 0;
	Node *origCurrNode;
	
	origCurrNode = origQueue.head;
	
	while (origCurrNode != 0) {
		push(origCurrNode->data);
		origCurrNode = origCurrNode->next;
	}
}

//Destructor
Queue::~Queue() {
    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

/*   Function:  push                         			        */
/*         in:  Pointer pirate to be added to the Queue         */
/*        out:  Int indicating success or failure               */
/*    Purpose:  Adds the pirate pointer to the end of the Queue */

int Queue::push(Pirate* newPirate) {
    Node *newNode;
    Node *currNode, *prevNode;

    newNode = new Node;
    newNode->data = newPirate;
    newNode->prev = 0;
    newNode->next = 0;

    prevNode = 0;
    currNode = head;

    while (currNode != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (prevNode == 0) {
        head = newNode;
    }
    else {
        prevNode->next = newNode;
        newNode->prev  = prevNode; 
    } 

    newNode->next = currNode;

    if (currNode != 0) {
        currNode->prev = newNode;
    }
    
    return C_OK;
}

/*   Function:  pop                         			        */
/*        out:  Int indicating success or failure               */
/*    Purpose:  Removes the pirate at the front of the Queue    */

int Queue::pop() {
    if (head != 0)
        return remove(head->data->getId());
    else 
        return C_NOK;
}

/*   Function:  front                         			        */
/*        out:  Pointer to the Pirate at the front of the Queue */
/*    Purpose:  Returns a pointer to the pirate at the front of */
/*              the queue                                       */

Pirate* Queue::front() {
    return head->data;
}

/*   Function:  empty                         			        */
/*        out:  Boolean indicating empty or non-empty           */
/*    Purpose:  Indicates whether or not the Queue is empty     */

bool Queue::empty() {
    if (head == 0)
        return true;
    else 
        return false;   
}

/*   Function:  remove                         			        */
/*         in:  ID of the pirate to be removed                  */
/*    Purpose:  Removes a pirate with the given ID from the     */
/*              Queue                                           */
/*              (the actual data is deleted in the removePirate */
/*              function)                                       */

int Queue::remove(int pirateId) {
    Node *currNode, *prevNode;

    prevNode = 0;
    currNode = head;

    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            break;
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == 0)
        return C_NOK;

    if (prevNode == 0) {
        head = currNode->next;
        if (head != 0)
            head->prev = 0;
    }
    else {
        prevNode->next = currNode->next;
        if (currNode->next != 0)
            currNode->next->prev = prevNode;
    }

    delete currNode;
    
    return C_OK;

}

/*   Function:  getPirateSpace                         			*/
/*         in:  ID of a pirate                                  */
/*        out:  The space of a pirate with matching ID          */
/*    Purpose:  Returns the space of a pirate (this is used     */
/*              when removing a pirate, in order to increase    */
/*              the space that is left in a cell after a pirate */
/*              is removed from it                              */

int Queue::getPirateSpace(int pirateId) {
    Node *currNode;
    
    currNode = head;
    
    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            return currNode->data->getSpace();
        currNode = currNode->next;
    }
    
    return 0;
}

/*   Function:  find                                 			*/
/*         in:  ID of a pirate                                  */
/*        out:  A pointer to the pirate with a matching ID      */
/*    Purpose:  Returns a pointer to the pirate that is being   */
/*              searched for                                    */
/*              (for deallocation purposes in the               */
/*              removePirate() function in the Brig)            */

Pirate* Queue::find(int pirateId) {
    Node *currNode;
    
    currNode = head;
    
    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            return currNode->data;
        currNode = currNode->next;
    }
    
    return 0;
}

/*   Function:  deleteData                             			*/
/*    Purpose:  Deletes the data contained in every Node in     */
/*              the Queue. This cannot be in the Queue's        */
/*              destructor because the temporary queue in       */
/*              the printBrig function calls the destructor     */
/*              and that queue should not be deleting the data  */

void Queue::deleteData() {
    Node *currNode, *nextNode;

    currNode = head;

    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }
}