#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Task.h"

class Processor
{
public:
	Processor(Queue q1, Queue q2, Queue q3);
	void run();
private:
	Task newTask();
	Stack stack;
	Queue queues[3];
	Task task;
	int tick = 100;
};

