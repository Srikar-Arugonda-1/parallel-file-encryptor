#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "Task.hpp"
#include <queue>
#include <memory>
#include <iostream>
#include <sys/wait.h>
#include <thread>

class Process {
    public:
        Process();
        bool submitToQueue(std::unique_ptr<Task> task);
        void executeTasks();
    private:
        std::queue<std::unique_ptr<Task>> taskQueue;
};

#endif