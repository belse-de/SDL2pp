//
// Created by belse on 27.02.18.
//

#include <iostream>

#include "libScheduling/src/Process.hpp"
#include "libScheduling/src/Scheduler.hpp"
#include "libScheduling/src/Strategies/RoundRobinStrategy.hpp"
#include "libScheduling/src/SystemTimer.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    SystemTimer timer(23ms);

    RoundRobinStrategy rr;
    Scheduler scheduler(rr); // won't call a final TIMEOUT in this simple implementation
    timer.subscribe(&scheduler);

    scheduler.addProcess("A");
    scheduler.addProcess("B");
    scheduler.addProcess("C");
    scheduler.addProcess("D");

    for(int i=0 ; i<4*3; ++i){
        timer.run();
    }

    scheduler.printStatistics();
    return 0;
}

/*
 * Sources:
 *   Round robin:
 *     https://www.codeproject.com/Questions/801175/Review-of-Round-robin-code-in-cplusplus
 *       2018-01-05T20:25
 *     https://www.thecrazyprogrammer.com/2015/09/round-robin-scheduling-program-in-c.html
 *       2018-01-05T20:30
*/
