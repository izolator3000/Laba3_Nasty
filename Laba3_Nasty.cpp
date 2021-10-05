#include <iostream>
#include <ctime>
#include "Queue.h"
#include "Processor.h"
#include "Task.h"
#include "Generator.h"
#include "windows.h"
using namespace std;



int main()
{
    setlocale(LC_ALL, "RU");
    srand(static_cast<unsigned int>(time(0)));

    Queue* q1 = new Queue(1);
    Queue* q2 = new Queue(2);
    Queue* q3 = new Queue(3);

    Generator* generator = new Generator(q1, q2, q3);
    Processor *proccessor = new Processor(q1, q2, q3);

    int timeToCreateTask = 0;
    int tack = 0;
    while (true)
    {
        tack++;
        cout << "Такт №" << tack << endl;

        
        
        timeToCreateTask = rand();
        if (timeToCreateTask % 3 == 2)
        {
            cout << "Создаём задание: ";
            Task* task = generator->GenerateTask();
            switch (task->getPriority())
            {
                case 1:
                    q1->insert(*task);
                    break;
                case 2:
                    q2->insert(*task);
                    break;
                case 3:
                    q3->insert(*task);
                    break;
                default:
                    break;
            }
        }

        proccessor->work();
        Sleep(1000);
    }




}
