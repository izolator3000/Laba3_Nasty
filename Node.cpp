#include "Node.h"



Node* Node::get_prev() {
    return prev;
}

Task Node::get_value() {
    return val;
}

void Node::set_prev(Node* elem) {
    prev = elem;
}