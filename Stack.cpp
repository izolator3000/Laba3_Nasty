#include "Stack.h"
#include "Task.h"
#include <vector>

Stack::Stack(){}

void Stack::insert(Task task)
{
	tasks.push_back(task);
}

Task Stack::remove()
{
	Task t = tasks[tasks.size()-1];
	tasks.pop_back();
	return t;
}


bool Stack::isempty()
{
	return tasks.empty();
}