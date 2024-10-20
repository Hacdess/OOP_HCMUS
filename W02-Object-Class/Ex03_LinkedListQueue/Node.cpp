#include "Node.h"

Node::Node(const int& data) {
    key = data;
    next = nullptr;
}

void Node::setNext(Node *node) {
    next = node;
}

int Node::getKey() const {
    return key;
}

Node *Node::getNext() const {
    return next;
}
