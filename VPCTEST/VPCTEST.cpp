#include <iostream>
#include <string>

#include "../VPCLOG/VPCLogger.h"

int main() {
    VPCLogger logger;

    logger.Log("TestProgram", "This is a normal message.");
    logger.Log("TestProgram", "This is a WARNING message.");
    logger.Log("TestProgram", "This is an ERROR message.");
    logger.Log("TestProgram", "Another normal message.");

    std::cout << "Press Enter to exit...";
    std::cin.ignore(); 
    std::cin.get(); 

    return 0;
}
