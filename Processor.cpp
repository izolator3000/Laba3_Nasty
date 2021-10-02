#include "Processor.h"
#include <iostream>
#include "Task.h"
using namespace std;

Processor::Processor(Queue q1, Queue q2, Queue q3)
{
    queues[0] = q1;
    queues[1] = q2;
    queues[2] = q3;
}

Task Processor::newTask()
{
    for (Queue q : queues)
    {
        if (!q.isempty())
        {
            return q.remove();
        }
    }
    return *new Task();
}


void Processor::run()
{
    while (true)
    {
        Task new_task = newTask();
        if (new_task == *new Task())
        {
            if (task.getDurationTime() <= 0)
            {
                if (stack.isempty())
                    cout << "Процессор в ожидании\n";
                else
                    task = stack.remove();
            }
            else
            {
                task.minusTime(tick);
            }          
        }
        else
        {
            if (new_task.getPriority() > task.getPriority())
            {
                stack.insert(task);
                task = new_task;
                task.minusTime(tick);
            }
            else
            {
                task.minusTime(tick);
            }
        }
    }
}