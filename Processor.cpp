#include "Processor.h"
#include <iostream>
#include "Task.h"
#include "Queue.h"
using namespace std;

Processor::Processor(Queue* q1, Queue* q2, Queue* q3):task(nullptr)
{
    queues[0] = q1;
    queues[1] = q2;
    queues[2] = q3;
    stack = new Stack();
}



void Processor::end()
{
    task->minusTime(tick);
    if (task->getDurationTime() <= 0)
    {
        cout << "Задание выполнено" << endl;
        task = nullptr;
    }
}

void Processor::work()
{
    cout << "Процессор начал работу\n";
    

    Task *new_task = nullptr;
    Task t;
    for (int i = 0; i < 3; i++)
    {
        if (!queues[i]->isempty())
        {
            t = queues[i]->pop();
            new_task = &t;
            cout << "Процессор у очереди " << queues[i]->Priority() << " получил задание\n";
            break;
        }
    }


    if (new_task == nullptr)
    {
        if (task == nullptr)
        {
            if (stack->isempty())
                cout << "Стек пуст. Процессор в ожидании" << endl;
            else
            {
                cout << "Взяли задачу из стека" << endl;
                t = stack->remove();
                task = &t;
            }
        }
    }
    else
    {
        if (task == nullptr)
        {
            cout << "Выполняем новое задание" << endl;
            task = new_task;
        }
        else
            if (task->getPriority() >= new_task->getPriority())
            {
                cout << "Помещаем новое задание в стек" << endl;
                stack->insert(*new_task);
            }
            else
            {
                cout << "Помещаем старое задание в стек" << endl;
                stack->insert(*task);
                cout << "Выполняем новое задание" << endl;
                task = new_task;
            }
    }
    if (task != nullptr)
    {
        task->minusTime(tick);
        task->show();
        if (task->getDurationTime() <= 0)
        {
            cout << "Задание выполнено" << endl;
            task = nullptr;
        }
    }
    
    cout << endl << endl;
}