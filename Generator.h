#pragma once
#include "Task.h"
#include "Queue.h"

class Generator
{
public:
    Generator();
    Generator(Queue* q1, Queue* q2, Queue* q3);
    Task* GenerateTask();
    void run();
    
private:
    void printTask(Task task);
    Queue* queues[3];
};


