#pragma once
#include "Task.h"
#include "Node.h"



class Queue {
    Node* start;
    Node* end;
    int priority;
public:
    Queue();
    Queue(int priority);
    void insert(Task val);
    Task pop();
    bool isempty();
    int Priority();
};
























//class Queue
//{
//public:
//    Queue();
//    Queue(int priority);
//    void insert(Task *task);
//    Task remove();
//    bool isempty();
//private:
//    int priority;
//    Task que[10];
//};


