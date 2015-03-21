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
        void pop();
        Pirate* front();
        int getPirateSpace(int);
        Pirate* find(int);
        void deleteData();
        Queue& operator+=(Pirate*);
        Queue& operator-=(Pirate*);
        Pirate* operator[](int);
        bool operator!();
    
    private:
        Node* head;
};

#endif
