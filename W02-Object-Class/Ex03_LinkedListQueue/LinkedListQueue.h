#ifndef _LINKED_LIST_QUEUE_H_
#define _LINKED_LIST_QUEUE_H_

#include "Node.h"

struct LinkedListQueue {
    private:
        Node *head; 
        Node *tail;
        int capacity;
        int num;

    public:
        void init(const int& inputCapacity); 
        void enqueue(int x);
        int dequeue();
        int peek();
        bool isEmpty();
        bool isFull();
        void clear();

        void output();
        void status();
};

#endif