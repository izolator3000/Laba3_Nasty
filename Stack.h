#pragma once
#include "Task.h"
#include <vector>
#include "Node.h"
using namespace std;



class Stack {
    Node* start;

public:
    Stack();
    void insert(Task val);
    Task remove();
    bool isempty();

};













//class Stack
//{
//public:
//	Stack();
//	void insert(Task task);
//	Task remove();
//	bool isempty();
//private:
//
//	vector<Task> tasks;
//};

