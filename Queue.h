#ifndef QUEUE_H
#define QUEUE_H

#include "Pirate.h"

class Queue
{
    class Node 
    {
        friend class Queue;
        private:
            Pirate* data;
            Node*   next;
            Node*   prev;
    };
    
    public:
        Queue();
        Queue(Queue&);
        ~Queue();
        int push(Pirate*);
        int pop();
        Pirate* front();
        bool empty();
        int getPirateSpace(int);
        Pirate* find(int);
        int remove(int);
		void deleteData();
    private:
        Node* head;
};

#endif
