#include "LinkedListQueue.h"

int main()
{
    LinkedListQueue queue;
    
    int capacity;
    cout << "Input the capacity of the queue: ";
    cin >> capacity;
    queue.init(capacity);
    queue.output();
    queue.status();
    cout << endl;

    int n;
    cout << "Input the number of elements to enqueue: ";
    cin >> n;
    
    int value;
    cout << "Input " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        queue.enqueue(value);
    }
    queue.output();
    queue.status();
    cout << endl;

    cout << "Input the number of elements to dequeue: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << queue.dequeue() << endl;
    queue.output();
    queue.status();
    cout << endl;

    queue.clear();
    queue.output();
    queue.status();
}