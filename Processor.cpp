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
        cout << "������� ���������" << endl;
        task = nullptr;
    }
}

void Processor::work()
{
    cout << "��������� ����� ������\n";
    

    Task *new_task = nullptr;
    Task t;
    for (int i = 0; i < 3; i++)
    {
        if (!queues[i]->isempty())
        {
            t = queues[i]->pop();
            new_task = &t;
            cout << "��������� � ������� " << queues[i]->Priority() << " ������� �������\n";
            break;
        }
    }


    if (new_task == nullptr)
    {
        if (task == nullptr)
        {
            if (stack->isempty())
                cout << "���� ����. ��������� � ��������" << endl;
            else
            {
                cout << "����� ������ �� �����" << endl;
                t = stack->remove();
                task = &t;
            }
        }
    }
    else
    {
        if (task == nullptr)
        {
            cout << "��������� ����� �������" << endl;
            task = new_task;
        }
        else
            if (task->getPriority() >= new_task->getPriority())
            {
                cout << "�������� ����� ������� � ����" << endl;
                stack->insert(*new_task);
            }
            else
            {
                cout << "�������� ������ ������� � ����" << endl;
                stack->insert(*task);
                cout << "��������� ����� �������" << endl;
                task = new_task;
            }
    }
    if (task != nullptr)
    {
        task->minusTime(tick);
        task->show();
        if (task->getDurationTime() <= 0)
        {
            cout << "������� ���������" << endl;
            task = nullptr;
        }
    }
    
    cout << endl << endl;
}