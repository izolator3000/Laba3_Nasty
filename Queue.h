#pragma once
#include "Task.h"
class Queue
{
public:
    Queue();
    Queue(int priority);
    void insert(Task *task);
    Task remove();
    bool isempty();
private:
    int priority;
    Task que[10];
};


