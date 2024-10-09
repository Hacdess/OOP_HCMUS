#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node* next;

    Node(const int& data);
};

struct LinkedListQueue
{
    Node *head; 
    Node *tail;
    int capacity;
    int num;

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