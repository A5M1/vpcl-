#ifndef VPCLOGGER_H
#define VPCLOGGER_H
#include <string>

class VPCLogger {
public:
    void Log(std::string programName, std::string output);

private:
    std::string GetCurrentDateTime();
};
#endif // VPCLOGGER_H
