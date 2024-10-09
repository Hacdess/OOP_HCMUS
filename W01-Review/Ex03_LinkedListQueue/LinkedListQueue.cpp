#include "LinkedListQueue.h"

Node::Node(const int& data)
{
    key = data;
    next = nullptr;
}

void LinkedListQueue::init(const int& inputCapacity)
{
    capacity = inputCapacity;
    num = 0;
    head = tail = nullptr;
}

void LinkedListQueue::enqueue(int x)
{
    if (num == capacity)
        return;

    num++;

    Node* node = new Node(x);

    if (!tail)
        head = tail = node;

    else
    {
        tail->next = node;
        tail= tail->next;
    }
}

int LinkedListQueue::dequeue()
{
    if (!head)
        return INT_MIN;

    Node* node = head;
    int result = node->key;
    head = head->next;
    delete node;

    num--;

    if (num == 0)
        tail = nullptr;

    return result;
}

int LinkedListQueue::peek()
{
    if (head)
        return head->key;
    
    return INT_MIN;
}

bool LinkedListQueue::isEmpty()
{
    return num == 0;
}

bool LinkedListQueue::isFull()
{
    return num == capacity;
}

void LinkedListQueue::clear()
{
    Node* cur;

    while (head)
    {
        cur = head;
        head = head->next;
        delete cur;
        cur = nullptr;
    }

    num = 0;
    tail = nullptr;
}

void LinkedListQueue::output()
{
    cout << "Queue: ";

    if (!head)
        cout << "Empty";
    else
    {
        Node* cur = head;
        while (cur)
        {
            cout << cur->key << ' ';
            cur = cur->next;
        }
    }
    
    cout << endl;
}

void LinkedListQueue::status()
{
    cout << "Status:\n";
    cout << "\tIs empty: " << isEmpty() << endl;
    cout << "\tIs full: " << isFull() << endl;
}
