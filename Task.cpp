#include "Task.h"

Task::Task(int priority, int taskTime, int durationTime) {
    this->priority = priority;
    this->taskTime = taskTime;
    this->durationTime = durationTime;
};
Task::Task() 
{
    priority = 0;
    taskTime = 0;
    durationTime = 0;
}
int Task::getPriority()
{
    return priority;
}
int Task::getTaskTime()
{
    return taskTime;
}
int Task::getDurationTime()
{
    return durationTime;
}
void Task::minusTime(int duration)
{
    durationTime -= duration;
}
void Task::operator=(Task* task)
{
    this->priority = task->getPriority();
    this->taskTime = task->getTaskTime();
    this->durationTime = task->getDurationTime();
}
bool Task::operator==(Task& task)
{
    return this->priority == task.getPriority() &&
           this->taskTime == task.getTaskTime() &&
           this->durationTime == task.getDurationTime();
}