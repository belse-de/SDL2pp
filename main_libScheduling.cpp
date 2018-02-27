//
// Created by belse on 27.02.18.
//

#include <iostream>

#include "lib/Process.hpp"
#include "lib/Scheduler.hpp"
#include "lib/Strategies/RoundRobinStrategy.hpp"
#include "lib/SystemTimer.hpp"

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
