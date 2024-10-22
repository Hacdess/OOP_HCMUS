#ifndef _LINKED_LIST_QUEUE_H_
#define _LINKED_LIST_QUEUE_H_

#include "Node.h"

class LinkedListQueue {
    private:
        Node *head; 
        Node *tail;
        int capacity;
        int num;

    public:
        void init(const int& capacity); 
        void enqueue(int x);
        int dequeue();
        int peek() const;
        bool isEmpty() const;
        bool isFull() const;
        void clear();
        void output() const;
        void status() const;
};

#endif