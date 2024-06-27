#include <iostream>
#include "Cryption.hpp"

int main(int argc, char const *argv[])
{
    if(argc != 2){
        std::cout << "Usage: ./cryption <taskData>" << std::endl;
        return 1;
    }
    executeCryption(argv[1]);
    return 0;
}
