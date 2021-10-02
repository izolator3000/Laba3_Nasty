#pragma once
class Task
{
public:
    Task();
    Task(int priority, int taskTime, int durationTime);
    int getPriority();
    int getTaskTime();
    int getDurationTime();
    void minusTime(int duration);
    bool operator==(Task& task);
    void operator=(Task* task);
private:
    int priority;
    int taskTime;
    int durationTime;
};

