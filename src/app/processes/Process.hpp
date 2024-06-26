#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "Task.hpp"
#include <queue>
#include <memory>

class Process {
    public:
        Process();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private:
        std::queue<std::unique_ptr<Task>> taskQueue;
};

#endif