//
// Created by belse on 09.01.18.
//

#include <catch.hpp>
#include "../Strategies/RoundRobinStrategy.hpp"

// TEST_CASE("","[]"){}

SCENARIO( "Scheduling strategy gives always correct next process position", "[RoundRobin]" ) {

    GIVEN("a RoundRobin strategy") {
        RoundRobinStrategy rr;

        WHEN("no processes are given"){
            std::vector<Process*> procList;

            THEN("next is not valid"){
                auto next = rr.next(procList);
                REQUIRE_FALSE(next);
            }
        }

        WHEN("only NULL processes are given"){
            std::vector<Process*> procList;
            for(int i=0; i<3; ++i){
                procList.push_back(nullptr);
            }

            THEN("next is not valid"){
                auto next = rr.next(procList);
                REQUIRE_FALSE(next);
            }
        }

        WHEN("two processes are given"){
            std::vector<Process*> procList;
            for(int i=0; i<3; ++i){
                procList.push_back(new Process());
            }

            THEN("next starts with 0 "){
                auto next = rr.next(procList);
                REQUIRE(next);
                REQUIRE(*next == 0u);
            }

            THEN("next counts up "){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 0u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);
            }
        }

        WHEN("one process is given on position 1"){
            std::vector<Process*> procList;
            procList.push_back(nullptr);
            procList.push_back(new Process());
            procList.push_back(nullptr);

            THEN("next return always returns1"){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);
            }
        }

        WHEN("one process is given on position 2"){
            std::vector<Process*> procList;
            procList.push_back(nullptr);
            procList.push_back(nullptr);
            procList.push_back(new Process());

            THEN("next return always returns2"){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);
            }
        }

        WHEN("two process are given on position 1 and2"){
            std::vector<Process*> procList;
            procList.push_back(nullptr);
            procList.push_back(new Process());
            procList.push_back(new Process());

            THEN("next return always returns 1,2"){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);
            }
        }

        WHEN("two process are given on position 0 and 1"){
            std::vector<Process*> procList;
            procList.push_back(new Process());
            procList.push_back(new Process());
            procList.push_back(nullptr);

            THEN("next return always returns 0,1"){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 0u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 0u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 1u);
            }
        }

        WHEN("two process are given on position 0 and 2"){
            std::vector<Process*> procList;
            procList.push_back(new Process());
            procList.push_back(nullptr);
            procList.push_back(new Process());

            THEN("next return always returns 0,2"){
                auto next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 0u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 0u);

                next = rr.next(procList);
                REQUIRE(next);
                CHECK(*next == 2u);
            }
        }
    }

}
