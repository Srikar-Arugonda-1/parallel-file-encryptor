#include <iostream>
#include <filesystem>
#include "./src/app/processes/Process.hpp"
#include "./src/app/processes/Task.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    std::string dir;
    std::string action;

    std::cout << "Enter Dir path: " << std::endl;
    std::getline(std::cin, dir);

    std::cout << "Action: " << std::endl;
    std::getline(std::cin, action);

    try {
        if(fs::exists(dir) && fs::is_directory(dir)){
            Process process;
            for(const auto &entry : fs::recursive_directory_iterator(dir)) {
                if(entry.is_regular_file()) {
                    std::string filePath = entry.path().string();
                    IO io(filePath);
                    std::fstream f_stream = std::move(io.getFileStream());
                    if(f_stream.is_open()) {
                        Action taskAction = (action == "ENCRYPT") ? Action::ENCRYPT : Action::DECRYPT;
                        auto task = std::make_unique<Task>(std::move(f_stream), taskAction, filePath);
                        process.submitToQueue(std::move(task));
                    } else {
                        std::cout << "Unable to open file: " << filePath << std::endl;
                    }
                }
            }
            process.executeTasks();
        } else {
            std::cout << "Invalid Dir path" << std::endl;
        }
    }
    catch(const fs::filesystem_error &ex) {
        std::cerr << "Filesystem error: " << ex.what() << std::endl;
    }
    

    return 0;
}


