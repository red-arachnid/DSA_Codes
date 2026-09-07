// Implement a simple task scheduler using a multimap<int, string> where key = priority (higher number = higher priority) 
// and value = task name. Support three operations:
// addTask(priority, task) — insert a task
// runNext() — remove and return the highest priority task (if tie in priority, return the one inserted first)
// cancelAll(priority) — remove all tasks at a given priority level

#include<bits/stdc++.h>
using namespace std;

class TaskScheduler {
    multimap<int, string, greater<int>> tasks;

public:
    void addTask(int priority, string task) {
        tasks.insert({priority, task});
    }

    string runNext() {
        if (tasks.begin() == tasks.end()) 
            throw runtime_error("No tasks remaining");

        auto it = tasks.begin();
        string task = it->second;
        tasks.erase(it);
        return task;
    }

    void cancelAll(int priority) {
        tasks.erase(priority);
    }
};

int main() {
    TaskScheduler tasks;
    tasks.addTask(1,"low");
    tasks.addTask(3,"high1");
    tasks.addTask(3,"high2");
    tasks.addTask(2,"mid");

    cout << tasks.runNext() << "\n";
    cout << tasks.runNext() << "\n";
    tasks.cancelAll(2);
    cout << tasks.runNext() << "\n";
}