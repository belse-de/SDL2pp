//
// Created by belse on 06.01.18.
//

#ifndef SCHEDULING_PROCESS_HPP
#define SCHEDULING_PROCESS_HPP


#include <iostream>
#include <chrono>
#include <variant>

#include "Printable.hpp"
#include "ProcessStatistics.hpp"

using namespace std::chrono_literals;

class Scheduler;

class Process : public Printable {
public:
    friend class Scheduler;

    //TODO: move constructor
    Process() : Process(0, "") {}

    Process(const int id, const std::string &name,
            std::chrono::milliseconds burstTime = 0ms,
            std::chrono::milliseconds arrivalTime = 0ms);

    virtual ~Process() = default;

    // signals
    enum class SignalEnum {
        NONE,
        ADMIT,
        DISPATCH,
        TIMEOUT,
        WAIT,
        AVAILABLE,
        RELEASE,
    };
    struct SignalNone {
    };

    struct SignalAdmit {
    };

    struct SignalDispatch {
    };

    struct SignalTimeout {
    };

    struct SignalWait {
    };

    struct SignalAvailable {
    };

    struct SignalRelease {
    };
    using Signal_t = std::variant<SignalNone, SignalAdmit, SignalDispatch, SignalTimeout, SignalWait, SignalAvailable, SignalRelease>;

    void signal(SignalEnum e = SignalEnum::NONE);

    void signal(Process::Signal_t &signal);

    // States
    enum class StateEnum {
        CREATED,
        READY,
        RUNNING,
        BLOCKED,
        TERMINATED,
    };
    struct State : public std::monostate, public Printable {
        virtual std::string toString() const = 0;

        Process *_thisProcess;
    };

    struct StateCreated : public State {
        std::string toString() const override;
    };

    struct StateReady : public State {
        StateReady(const State &state);

        std::string toString() const override;
    };

    struct StateRunning : public State {
        StateRunning(const State &state);

        std::string toString() const override;
    };

    struct StateBlocked : public State {
        StateBlocked(const State &state);

        std::string toString() const override;
    };

    struct StateTerminated : public State {
        StateTerminated(const State &state);

        std::string toString() const override;
    };

    using State_t = std::variant<StateCreated, StateReady, StateRunning, StateBlocked, StateTerminated>;
    StateEnum state();

    //transitions
    struct TransitionTable {
        TransitionTable(Process *process) : _thisProcess{process} { ; }

        Process *_thisProcess;

        ////////////////
        // state: create
        ////////////////
        State_t operator()(const StateCreated &state, const SignalNone &signal) { return state; }

        State_t operator()(StateCreated &state, const SignalAdmit &signal) {
            state._thisProcess = _thisProcess;
            return StateReady(state);
        }

        State_t operator()(const StateCreated &state, const SignalDispatch &signal) { return state; }

        State_t operator()(const StateCreated &state, const SignalTimeout &signal) { return state; }

        State_t operator()(const StateCreated &state, const SignalWait &signal) { return state; }

        State_t operator()(const StateCreated &state, const SignalAvailable &signal) { return state; }

        State_t operator()(const StateCreated &state, const SignalRelease &signal) { return state; }

        ////////////////
        // state: ready
        ////////////////
        State_t operator()(const StateReady &state, const SignalNone &signal) { return state; }

        State_t operator()(const StateReady &state, const SignalAdmit &signal) { return state; }

        State_t operator()(const StateReady &state, const SignalDispatch &signal) { return StateRunning(state); }

        State_t operator()(const StateReady &state, const SignalTimeout &signal) { return state; }

        State_t operator()(const StateReady &state, const SignalWait &signal) { return state; }

        State_t operator()(const StateReady &state, const SignalAvailable &signal) { return state; }

        State_t operator()(const StateReady &state, const SignalRelease &signal) { return state; }

        ////////////////
        // state: running
        ////////////////
        State_t operator()(const StateRunning &state, const SignalNone &signal) { return state; }

        State_t operator()(const StateRunning &state, const SignalAdmit &signal) { return state; }

        State_t operator()(const StateRunning &state, const SignalDispatch &signal) { return state; }

        State_t operator()(const StateRunning &state, const SignalTimeout &signal) { return StateReady(state); }

        State_t operator()(const StateRunning &state, const SignalWait &signal) { return StateBlocked(state); }

        State_t operator()(const StateRunning &state, const SignalAvailable &signal) { return state; }

        State_t operator()(const StateRunning &state, const SignalRelease &signal) { return StateTerminated(state); }

        ////////////////
        // state: blocked
        ////////////////
        State_t operator()(const StateBlocked &state, const SignalNone &signal) { return state; }

        State_t operator()(const StateBlocked &state, const SignalAdmit &signal) { return state; }

        State_t operator()(const StateBlocked &state, const SignalDispatch &signal) { return state; }

        State_t operator()(const StateBlocked &state, const SignalTimeout &signal) { return state; }

        State_t operator()(const StateBlocked &state, const SignalWait &signal) { return state; }

        State_t operator()(const StateBlocked &state, const SignalAvailable &signal) { return StateReady(state); }

        State_t operator()(const StateBlocked &state, const SignalRelease &signal) { return state; }

        ////////////////
        // state: terminated
        ////////////////
        State_t operator()(const StateTerminated &state, const SignalNone &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalAdmit &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalDispatch &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalTimeout &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalWait &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalAvailable &signal) { return state; }

        State_t operator()(const StateTerminated &state, const SignalRelease &signal) { return state; }
    };


    bool resume() const {
        std::cout << "resuming   " << toString() << std::endl;
        return true;
    }

    bool suspend() const {
        std::cout << "suspending " << toString() << std::endl;
        return true;
    }

    std::string toString() const override;

    bool isFinished() {
        return state() == StateEnum::TERMINATED;
    }

private:
    const int _id = -1;
    const std::string _name = "";
    ProcessStatistics _statisitics;
    State_t _state;
};

#endif //SCHEDULING_PROCESS_HPP
