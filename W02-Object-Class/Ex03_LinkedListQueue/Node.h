#ifndef _NODE_H
#define _NODE_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Node {
    private:
        int key;
        Node* next;

    public:
        Node(const int& data);
};

#endif