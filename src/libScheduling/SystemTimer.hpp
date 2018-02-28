//
// Created by belse on 15.02.18.
//

#ifndef SCHEDULING_SYSTEMTIMER_HPP
#define SCHEDULING_SYSTEMTIMER_HPP


#include <chrono>
#include <vector>
#include "SystemTimerSubscriber.hpp"

using namespace std::chrono_literals;

struct EventSystemTimerInterrupt{
    std::chrono::milliseconds systick;
};

class SystemTimer {

public:

    SystemTimer() : SystemTimer(1ms) {};

    SystemTimer(std::chrono::milliseconds timerInterruptPeriod) : _timerInterruptPeriod{timerInterruptPeriod} {}

    void subscribe( SystemTimerSubscriber *subscriber){
        _subscribers.push_back(subscriber);
    }

    void run(){
        _systick += _timerInterruptPeriod;
        EventSystemTimerInterrupt e{_systick};
        for(auto sub_ptr : _subscribers){
            sub_ptr->event(e);
        }
    }

private:
    std::chrono::milliseconds _timerInterruptPeriod;
    std::chrono::milliseconds _systick = 0ms;
    std::vector<SystemTimerSubscriber*> _subscribers;
};


#endif //SCHEDULING_SYSTEMTIMER_HPP
