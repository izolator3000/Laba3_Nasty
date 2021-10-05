#include "Generator.h"
#include <iostream>
#include <ctime>
#include "windows.h"
#include "Task.h"
#include "Queue.h"

using namespace std;

Generator::Generator(Queue* q1, Queue* q2, Queue* q3)
{
    queues[0] = q1;
    queues[1] = q2;
    queues[2] = q3;
}
Generator::Generator() {};

void Generator::printTask(Task task)
{
    cout << "priority: " <<task.getPriority();
    cout << "\ttask time: " << task.getTaskTime();
    cout <<"\tduration time: "<< task.getDurationTime() << endl;
}


Task* Generator::GenerateTask()
{
    Task* task = new Task(rand() % 3 + 1, rand() % 20 + 1, rand() % 5 + 1); //TODO: изменить случайное число на системноеврем¤
    printTask(*task);
    return task;

    //Task* task = new Task(1, 34, 4);
    //return task;
}

void Generator::run()
{
    /*srand(static_cast<unsigned int>(time(0)));
    int timeToCreateTask = 0;
    while (true)
    {
        timeToCreateTask = rand();
        if (timeToCreateTask % 3 == 2)
        {
            Task *task = GenerateTask();
            switch (task->getPriority())
            {
            case 1:
                queues[0]->insert(*task);
                break;
            case 2:
                queues[1]->insert(*task);
                break;
            case 3:
                queues[2]->insert(*task);
                break;
            default:
                break;
            }
            
        }
        
    }*/
}