#include "Queue.h"
#include "Task.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Queue::Queue(int priority) : end(nullptr), start(nullptr), priority(priority) {}
Queue::Queue():end(nullptr), start(nullptr), priority(0) {}


void Queue::insert(Task val) {
    cout << "Очередь с приоритетом " << priority << " получила задание" << endl;

    Node* elem = new Node(val);
    if (isempty()) {
        start = elem;
        end = elem;
    }
    else {
        end->set_prev(elem);
        end = elem;
    }
}



Task Queue::pop() {
    if (isempty())
        throw std::logic_error("queue is empty!");

    Node* prev_elem = start->get_prev();
    Task ret_value = start->get_value();
    delete start;
    start = prev_elem;
    return ret_value;
}



bool Queue::isempty() {
    return start == nullptr;
}



int Queue::Priority()
{
    return priority;
}
















//Queue::Queue(int priority)
//{
//    this->priority = priority;
//    for (int i = 0; i < 10; i++)
//    {
//        que[i] = Task();
//    }
//}
//Queue::Queue() { priority = 0; }
//
//void Queue::insert(Task *task)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        if (que[i] == *new Task())
//        {
//            que[i] = task;
//            return;
//        }
//    }
//    for (int i = 0; i < 9; i++)
//    {
//        que[i] = que[i + 1];
//    }
//    que[9] = task;
//}
//
//
//Task Queue::remove()
//{
//    Task t = que[0];
//    for (int i = 0; i < 9; i++)
//    {
//        que[i] = que[i + 1];
//    }
//    que[9] = *new Task();
//    return t;
//}
//
//bool Queue::isempty()
//{
//    return que[0] == *new Task();
//}