#include "LinkedListQueue.h"

int main() {
    LinkedListQueue queue;
    
    int capacity;
    cout << "Input the capacity of the queue: ";
    cin >> capacity;
    queue.init(capacity);
    queue.output();
    queue.status();
    cout << endl;

    int n;
    do {
        cout << "Input the number (non-negative integer) of elements to enqueue: ";
        cin >> n;
    } while (n < 0);
    
    int value;
    cout << "Input " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        queue.enqueue(value);
    }
    queue.output();
    queue.status();
    cout << endl;

    do {
        cout << "Input the number (non-negative integer) of elements to dequeue: ";
        cin >> n;
    } while (n < 0);

    try {
        cout << "Peek: " << queue.peek() << endl;
    }
    catch(const invalid_argument& e) {
        cout << e.what() << '\n';
    }
    
    for (int i = 0; i < n; i++) {
        try {
            cout << "Removed: " << queue.dequeue();
        }
        catch(const invalid_argument& e) {
            cout << e.what();
        }

        try {
            cout << " - Peek: " << queue.peek() << endl;
        }
        catch(const invalid_argument& e) {
            cout << e.what() << '\n';
        }
    }

    queue.output();
    queue.status();
    cout << endl;

    queue.clear();
    queue.output();
    queue.status();

    return 0;
}