//
// Created by belse on 06.01.18.
//

#ifndef SCHEDULING_SCHEDULER_HPP
#define SCHEDULING_SCHEDULER_HPP

#include <vector>
#include <iomanip>
#include <algorithm>
#include "SchedulingStrategy.hpp"
#include "SystemTimerSubscriber.hpp"
#include "SystemTimer.hpp"

class Scheduler : public SystemTimerSubscriber {
public:
    Scheduler(SchedulingStrategy &strategy) : _strategy{strategy} {}

    virtual ~Scheduler() {
        for (auto process_ptr : _processes) {
            if (process_ptr != nullptr) {
                delete process_ptr;
                process_ptr = nullptr;
            }
        }
    }

    void addProcess(const std::string &name) {
        static int newID = 0;
        Process *newProcess = new Process(newID++, name);
        _processes.push_back(newProcess);
        newProcess->signal(Process::SignalEnum::ADMIT);
    }

    void event(const EventSystemTimerInterrupt &e) override {
        //TODO: implement run
        // process list is empty
        if (_processes.empty()
            or (*_processes.begin() == nullptr and
                std::adjacent_find(_processes.begin(), _processes.end(), std::not_equal_to<Process*>()) ==
                _processes.end())) {
            return;
        }

        // new time slice
        if (e.systick - _startLastSlice >= _timeQuantum) {
            _startLastSlice = e.systick;

            auto next = _strategy.next(_processes);
            // nothing to schedule;
            if (not next) {
                return;
            }

            // new process for scheduling
            if (*next != _lastProcess) {
                // pause after time Quantum
                if (Process* last_proc_ptr = _processes[_lastProcess];
                last_proc_ptr and last_proc_ptr->state() == Process::StateEnum::RUNNING){
                    last_proc_ptr->signal(Process::SignalEnum::TIMEOUT);
                }
            }

            // schedule new process
            _processes[*next]->signal(Process::SignalEnum::DISPATCH);
            _lastProcess = *next;
        }

        // current process is going to finish in this time slice
        // current process does not finish in slice
        // stop current process and calc and print statistics

        //new time slice
        // in time slice
        // time slice or process finished
    }

    void printStatistics() {
        std::chrono::milliseconds totalWaitingTime = 0ms;
        std::chrono::milliseconds totalTurnAroundTime = 0ms;

        std::cout << "\n\n\n"
                  << "--------------------------------------------------" << "\n"
                  << "  ID    BT    AT    ST    ET    WT    TT    Name  " << "\n"
                  << "--------------------------------------------------" << "\n";
        for (auto p : _processes) {
            std::cout << std::setw(6) << p->_id
                      << std::setw(6) << p->_statisitics._burstTime.count()
                      << std::setw(6) << p->_statisitics._arrivalTime.count()
                      << std::setw(6) << p->_statisitics._stopTime.count()
                      << std::setw(6) << p->_statisitics._executionTime.count()
                      << std::setw(6) << p->_statisitics._waitingTime.count()
                      << std::setw(6) << p->_statisitics._turnAroundTime.count()
                      << " " << std::setw(8) << *p
                      << "\n";
            totalWaitingTime += p->_statisitics._waitingTime;
            totalTurnAroundTime += p->_statisitics._turnAroundTime;
        }
        std::cout << "--------------------------------------------------" << "\n";
        std::cout << "Average Waiting Time:    " << std::setw(8) << 1.0 * totalWaitingTime.count() / _processes.size()
                  << "\n";
        std::cout << "Average Turn Around Time:" << std::setw(8)
                  << 1.0 * totalTurnAroundTime.count() / _processes.size() << "\n";
        std::cout << "For a quatum of:         " << std::setw(8) << _timeQuantum.count() << "ms \n"
                  << "For a total time of:     " << std::setw(8) << _totalTime.count() << "ms \n"
                  << "for number of:           " << std::setw(8) << _processes.size() << " process(es). \n";
        std::cout << std::flush;
    }


    SchedulingStrategy &_strategy;
    std::vector<Process *> _processes;
private:
    size_t _lastProcess = 0;

    std::chrono::milliseconds _timeQuantum = 10ms;
    std::chrono::milliseconds _totalTime = 0ms;
    std::chrono::milliseconds _startLastSlice = 0ms;

};


#endif //SCHEDULING_SCHEDULER_HPP
