#include "Queue.h"
#include "Task.h"

Queue::Queue(int priority)
{
    this->priority = priority;
    for (int i = 0; i < 10; i++)
    {
        que[i] = Task();
    }
}
Queue::Queue() { priority = 0; }

void Queue::insert(Task *task)
{
    for (int i = 0; i < 10; i++)
    {
        if (que[i] == *new Task())
        {
            que[i] = task;
            return;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        que[i] = que[i + 1];
    }
    que[9] = task;
}


Task Queue::remove()
{
    Task t = que[0];
    for (int i = 0; i < 9; i++)
    {
        que[i] = que[i + 1];
    }
    que[9] = *new Task();
    return t;
}

bool Queue::isempty()
{
    return que[0] == *new Task();
}