#include "Stack.h"
#include "Task.h"
#include <vector>
#include "Node.h"
#include <stdexcept>
using namespace std;


Stack::Stack() :start(nullptr) {}

void Stack::insert(Task val) {
    Node* elem = new Node(val);
    if (isempty()) {
        start = elem;

    }
    else {
        elem->set_prev(start);
        start = elem;
    }
}

Task Stack::remove() {
    if (isempty())
        throw logic_error("queue is empty!");

    Node* temp_elem = start;
    Task temp_val = start->get_value();
    start = start->get_prev();
    delete temp_elem;
    return temp_val;

}


bool Stack::isempty() {
    return start == nullptr;
}













//Stack::Stack(){}
//
//void Stack::insert(Task task)
//{
//	tasks.push_back(task);
//}
//
//Task Stack::remove()
//{
//	Task t = tasks[tasks.size()-1];
//	tasks.pop_back();
//	return t;
//}
//
//
//bool Stack::isempty()
//{
//	return tasks.empty();
//}