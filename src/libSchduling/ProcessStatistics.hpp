//
// Created by belse on 27.01.18.
//

#ifndef SCHEDULING_PROCESSSTATISTICS_HPP
#define SCHEDULING_PROCESSSTATISTICS_HPP

#include <chrono>

using namespace std::chrono_literals;
class ProcessStatistics {


public:
    void updateTimes(std::chrono::milliseconds currentTime) {
        _stopTime = currentTime;
        _turnAroundTime = _stopTime - _arrivalTime;
        _waitingTime = _turnAroundTime - _burstTime;
    }

    std::chrono::milliseconds _arrivalTime = 0ms;
    std::chrono::milliseconds _burstTime = 0ms;
    std::chrono::milliseconds _executionTime = 0ms;
    std::chrono::milliseconds _stopTime = 0ms;
    std::chrono::milliseconds _turnAroundTime = 0ms;
    std::chrono::milliseconds _waitingTime = 0ms;
};


#endif //SCHEDULING_PROCESSSTATISTICS_HPP
