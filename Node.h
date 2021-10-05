#pragma once
#include "Task.h"

class Node {
    Node* prev;
    Task val;
public:
    Node(Task val, Node* prev = nullptr) :prev(prev), val(val) {}
    void set_prev(Node* elem);
    Task get_value();
    Node* get_prev();
};

