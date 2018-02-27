//
// Created by belse on 15.02.18.
//

#ifndef SCHEDULING_SYSTEMTIMERSUBSCRIBER_HPP
#define SCHEDULING_SYSTEMTIMERSUBSCRIBER_HPP


class EventSystemTimerInterrupt;

class SystemTimerSubscriber {
public:
    virtual void event(const EventSystemTimerInterrupt &e) = 0;
};


#endif //SCHEDULING_SYSTEMTIMERSUBSCRIBER_HPP
