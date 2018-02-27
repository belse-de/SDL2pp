//
// Created by belse on 06.01.18.
//

#ifndef SCHEDULING_ROUNDROBINSTRATEGY_HPP
#define SCHEDULING_ROUNDROBINSTRATEGY_HPP

#include "../SchedulingStrategy.hpp"

class RoundRobinStrategy : public SchedulingStrategy{
public:
    RoundRobinStrategy() : _isInit(false), _current(0), _next(0) {}

    virtual std::optional<size_t> next(const std::vector<Process*> &processes) override {
        //only active if there are processes
        if(processes.size() > 0){
            _current = _next;

            // we are in an non valid state init
            if(not _isInit
               or processes.at(_current) == nullptr
               or processes.at(_current)->isFinished()){
                _next = _current;
                do{
                    if(processes.at(_next) != nullptr
                       and not processes.at(_next)->isFinished()) {
                        // found current process
                        _isInit = true;
                        _current = _next;
                        break;
                    }
                    _next = (_next + 1) % processes.size();
                }while(_next != _current);
            }

            // find next process
            do{
                _next = (_next + 1) % processes.size();
                if(processes.at(_next) != nullptr
                    and not processes.at(_next)->isFinished()) {
                    // found next process
                    break;
                }
            }while(_next != _current);

            // the result is valid
            if(_isInit) {
                return _current;
            }
        }
        return {};
    }

private:
    bool _isInit;
    size_t _current;
    size_t _next;
};


#endif //SCHEDULING_ROUNDROBINSTRATEGY_HPP
