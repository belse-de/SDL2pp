//
// Created by belse on 27.01.18.
//

#include <catch.hpp>

#include "../lib/Process.hpp"

using Catch::Matchers::Equals;

TEST_CASE("Process", "[scratch][vatriantfsm][fsm]") {
    Process process;

    SECTION("basic example") {
        CHECK(process.state() == Process::StateEnum::CREATED);

        process.signal(Process::SignalEnum::ADMIT);
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(Process::SignalEnum::DISPATCH);
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(Process::SignalEnum::TIMEOUT);
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(Process::SignalEnum::DISPATCH);
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(Process::SignalEnum::WAIT);
        CHECK(process.state() == Process::StateEnum::BLOCKED);

        process.signal(Process::SignalEnum::AVAILABLE);
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(Process::SignalEnum::DISPATCH);
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(Process::SignalEnum::RELEASE);
        CHECK(process.state() == Process::StateEnum::TERMINATED);
    }

    SECTION("basic example with Signal objects") {
        Process::Signal_t currentSignal;
        CHECK(process.state() == Process::StateEnum::CREATED);

        process.signal(currentSignal = Process::SignalAdmit());
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(currentSignal = Process::SignalDispatch());
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(currentSignal = Process::SignalTimeout());
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(currentSignal = Process::SignalDispatch());
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(currentSignal = Process::SignalWait());
        CHECK(process.state() == Process::StateEnum::BLOCKED);

        process.signal(currentSignal = Process::SignalAvailable());
        CHECK(process.state() == Process::StateEnum::READY);

        process.signal(currentSignal = Process::SignalDispatch());
        CHECK(process.state() == Process::StateEnum::RUNNING);

        process.signal(currentSignal = Process::SignalRelease());
        CHECK(process.state() == Process::StateEnum::TERMINATED);
    }

    SECTION("bug: missing break between AVAILABLE and RELEASE") {
        CHECK(process.state() == Process::StateEnum::CREATED);


        process.signal(Process::SignalEnum::ADMIT);
        CHECK(process.state() == Process::StateEnum::READY);


        process.signal(Process::SignalEnum::DISPATCH);
        CHECK(process.state() == Process::StateEnum::RUNNING);


        process.signal(Process::SignalEnum::AVAILABLE);
        CHECK(process.state() == Process::StateEnum::RUNNING);

    }

    SECTION("bug: missing break between AVAILABLE and RELEASE with Signal objects") {
        CHECK(process.state() == Process::StateEnum::CREATED);
        Process::Signal_t currentSignal;

        process.signal(currentSignal = Process::SignalAdmit());
        CHECK(process.state() == Process::StateEnum::READY);


        process.signal(currentSignal = Process::SignalDispatch());
        CHECK(process.state() == Process::StateEnum::RUNNING);


        process.signal(currentSignal = Process::SignalAvailable());
        CHECK(process.state() == Process::StateEnum::RUNNING);

    }
}
