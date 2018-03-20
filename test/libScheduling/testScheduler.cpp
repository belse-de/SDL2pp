//
// Created by belse on 22.02.18.
//

#include "../../extern/catch.hpp"
#include <libScheduling/SystemTimer.hpp>
#include <libScheduling/Strategies/RoundRobinStrategy.hpp>
#include <libScheduling/Scheduler.hpp>

TEST_CASE("simple run scheduler round robin", "[roundrobin][scheduler]") {
    SystemTimer timer(23ms);

    RoundRobinStrategy rr;
    Scheduler scheduler(rr); // won't call a final TIMEOUT in this simple implementation
    timer.subscribe(&scheduler);

    scheduler.addProcess("A");
    scheduler.addProcess("B");
    scheduler.addProcess("C");
    scheduler.addProcess("D");

    for (int i = 0; i < 4 * 3; ++i) {
        timer.run();
        REQUIRE(scheduler._processes[i % 4]->state() == Process::StateEnum::RUNNING);
        REQUIRE(scheduler._processes[(i + 1) % 4]->state() == Process::StateEnum::READY);
        REQUIRE(scheduler._processes[(i + 2) % 4]->state() == Process::StateEnum::READY);
        REQUIRE(scheduler._processes[(i + 3) % 4]->state() == Process::StateEnum::READY);
    }
}
