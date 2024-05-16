#include "VPCLogger.h"
#include <string>
#include <regex>
#include <iostream>
#include <chrono>
#include <Windows.h>
/// <summary>
/// 
/// </summary>
/// <param name="programName"></param>
/// <param name="output"></param>
void VPCLogger::Log(std::string programName, std::string output) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_GREEN);
    std::cout << GetCurrentDateTime() << "," << programName;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

    output = std::regex_replace(output, std::regex("(?i)WARNING"), "\033[1;41m\033[37mWARNING\033[0m");
    output = std::regex_replace(output, std::regex("(?i)ERROR"), "\033[1;41m\033[37mERROR\033[0m");

    if (output.find("error") != std::string::npos || output.find("warning") != std::string::npos)
        Beep(102, 2);
    else
        std::cout << output << std::endl;
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
std::string VPCLogger::GetCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    char buffer[20];
    tm timeinfo;
    localtime_s(&timeinfo, &now_time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    return buffer;
}
