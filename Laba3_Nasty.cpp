#include <iostream>
#include <ctime>
#include "Queue.h"
#include "Processor.h"
#include "Task.h"
#include "Generator.h"
using namespace std;






int main()
{
    setlocale(LC_ALL, "RU");
    Queue *q1 = new Queue(1);
    Queue *q2 = new Queue(2);
    Queue *q3 = new Queue(3);

    Generator *generator = new Generator(*q1, *q2, *q3);

    Processor *proccessor = new Processor(*q1, *q2, *q3);

    proccessor->run();
    generator->run();






    //Queue* queue = new Queue();
    //Generator* generator = new Generator();
    //for (int i = 0; i < 10; i++)
    //    queue->insert(*generator->GenerateTask());

    //for (int i = 0; i < 10; i++)
    //    generator->printTask(queue->remove(i));
    
}
