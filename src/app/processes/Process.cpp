#include "Process.hpp"
#include <iostream>
#include <sys/wait.h>

Process::Process() {}

bool Process::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(task);
    return true;
}

void Process::executeTasks(){
    while(!taskQueue.empty()){
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout << "Executing Task: " << taskToExecute->toString() << std::endl;
        // executeCryption(taskToExecute->toString());
    }
}