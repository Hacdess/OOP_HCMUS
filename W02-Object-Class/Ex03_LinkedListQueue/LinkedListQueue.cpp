#include "LinkedListQueue.h"

void LinkedListQueue::init(const int &capacity) {
    if (capacity <= 0) {
        cout << "Capacity must be greater than zero!\n";
        this->capacity = 0;
    } else
        this->capacity = capacity;

    num = 0;
    head = tail = nullptr;
}

void LinkedListQueue::enqueue(int x) {
    if (num == capacity) {
        cout << "Error: Can't enqueue " << x << " because the queue is full!\n";
        return;
    }

    num++;

    Node* node = new Node(x);

    if (!tail)
        head = tail = node;

    else {
        tail->setNext(node);
        tail = node;
    }
}

int LinkedListQueue::dequeue() {
    if (!head)
        throw invalid_argument("Error: Can't dequeue because the queue is empty!");

    Node* node = head;
    int result = node->getKey();
    head = head->getNext();
    delete node;

    num--;

    if (num == 0)
        tail = nullptr;

    return result;
}

int LinkedListQueue::peek() const {
    if (!head)
        throw invalid_argument("Error: Can't get peek because the queue is empty!");

    return head->getKey();    
}

bool LinkedListQueue::isEmpty() const {
    return num == 0;
}

bool LinkedListQueue::isFull() const {
    return num == capacity;
}

void LinkedListQueue::clear() {
    Node* cur;

    while (head) {
        cur = head;
        head = head->getNext();
        delete cur;
    }

    num = 0;
    tail = nullptr;
}

void LinkedListQueue::output() const {
    cout << "Queue: ";

    if (!head)
        cout << "Empty";
    else {
        Node* cur = head;
        while (cur)
        {
            cout << cur->getKey() << ' ';
            cur = cur->getNext();
        }
    }
    
    cout << endl;
}

void LinkedListQueue::status() const {
    cout << "Status:\n";
    cout << "\tNumber of elements: " << num << "/" << capacity << endl;
    cout << "\tIs empty: " << (isEmpty() ? "Yes" : "No") << endl;
    cout << "\tIs full: " << (isFull() ? "Yes" : "No") << endl;
}
