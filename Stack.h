#pragma once
#include "Task.h"
#include <vector>
using namespace std;

class Stack
{
public:
	Stack();
	void insert(Task task);
	Task remove();
	bool isempty();
private:

	vector<Task> tasks;
};

