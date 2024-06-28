// CurrentTime.h
#pragma once
#include <fstream>
#include <chrono>
#include <ctime>

class CurrentTime {
public:
    void getCurrentTime();
    void writeToFile(const std::string& fileName) const;

private:
    std::chrono::system_clock::time_point currentTime;
    std::time_t currentTimeInTimeT;
    std::tm* currentTimeInfo;
};

