//
// Created by belse on 06.01.18.
//

#include "Process.hpp"
#include "../extern/overloaded.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

Process::Process(const int id, const string &name,
                 milliseconds burstTime,
                 milliseconds arrivalTime)
    : _id{id}, _name{name} {
    _statisitics._burstTime = burstTime;
    _statisitics._arrivalTime = arrivalTime;
}

void Process::signal(SignalEnum e) {
    Signal_t s;
    switch (e) {
        case SignalEnum::NONE:
            signal(s = SignalNone());
            break;
        case SignalEnum::ADMIT:
            signal(s = SignalAdmit());
            break;
        case SignalEnum::DISPATCH:
            signal(s = SignalDispatch());
            break;
        case SignalEnum::TIMEOUT:
            signal(s = SignalTimeout());
            break;
        case SignalEnum::WAIT:
            signal(s = SignalWait());
            break;
        case SignalEnum::AVAILABLE:
            signal(s = SignalAvailable());
            break;
        case SignalEnum::RELEASE:
            signal(s = SignalRelease());
            break;
    }
}

Process::StateEnum Process::state() {
    //return StateEnum::CREATED;
    return visit(overloaded {
                     [](const StateCreated &) { return StateEnum::CREATED; },
                     [](const StateReady &) { return StateEnum::READY; },
                     [](const StateRunning &) { return StateEnum::RUNNING; },
                     [](const StateBlocked &) { return StateEnum::BLOCKED; },
                     [](const StateTerminated &) { return StateEnum::TERMINATED; },
                 },
                 _state
    );
}

std::string Process::toString() const {
    return
        _name + ": "
        + visit(
        [](const Printable &state) { return state.toString(); },
        _state
    );
}

void Process::signal(Process::Signal_t &signal) {
    _state = visit(TransitionTable(this), _state, signal);
}

string Process::StateCreated::toString() const {
    return "state: created   ";
}

string Process::StateReady::toString() const {
    return "state: ready     ";
}

Process::StateReady::StateReady(const Process::State &state) {
    _thisProcess = state._thisProcess;
}

string Process::StateRunning::toString() const {
    return "state: running   ";
}

Process::StateRunning::StateRunning(const Process::State &state) {
    _thisProcess = state._thisProcess;
}

string Process::StateBlocked::toString() const {
    return "state: blocked   ";
}

Process::StateBlocked::StateBlocked(const Process::State &state) {
    _thisProcess = state._thisProcess;
}

string Process::StateTerminated::toString() const {
    return "state: terminated";
}

Process::StateTerminated::StateTerminated(const Process::State &state) {
    _thisProcess = state._thisProcess;
}
