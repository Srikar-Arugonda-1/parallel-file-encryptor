#include "Process.hpp"
#include "../encryptDecrypt/Cryption.hpp"

void encryptFile(std::unique_ptr<Task> task) {
    std::cout << "Encrypting File: " << task->toString() << std::endl;
    executeCryption(task->toString());
}

Process::Process() {}

bool Process::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void Process::executeTasks(){
    int maxThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    while(!taskQueue.empty()){
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();

        if(threads.size() >= maxThreads) {
            for(auto& t: threads) {
                t.join();
            }
            threads.clear();
        }

        // executeCryption(taskToExecute->toString());
        /* Create Threads here */
        threads.emplace_back(encryptFile, std::move(taskToExecute));
    }

    for (auto& t : threads) {
        t.join();
    }
}
