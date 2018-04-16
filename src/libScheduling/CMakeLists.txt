cmake_minimum_required(VERSION 3.8)
project(sdl2pp_scheduling CXX C)
########################################################################################################################
# lib scheduling
########################################################################################################################
set(SOURCES_LIB_SCHEDULING
        src/Process.cpp
        src/Process.hpp
        src/ProcessStatistics.cpp
        src/ProcessStatistics.hpp
        src/Scheduler.cpp
        src/Scheduler.hpp
        src/SchedulingStrategy.cpp
        src/SchedulingStrategy.hpp
        src/Strategies/RoundRobinStrategy.cpp
        src/Strategies/RoundRobinStrategy.hpp
        src/Strategies/ShortesJobFirstStrategy.cpp
        src/Strategies/ShortesJobFirstStrategy.hpp
        src/Strategies/FirstComeFirstServedStrategy.cpp
        src/Strategies/FirstComeFirstServedStrategy.hpp
        src/Strategies/PriorityStrategy.cpp
        src/Strategies/PriorityStrategy.hpp
        src/SystemTimerSubscriber.cpp
        src/SystemTimerSubscriber.hpp
        src/SystemTimer.cpp
        src/SystemTimer.hpp)
set(SOURCES_TEST_SCHEDULING
        test/catchMain.cpp
        test/testProcess.cpp
        test/testRoundRobin.cpp
        test/testScheduler.cpp)
set(SOURCES_EXE_SCHEDULING
        main_libScheduling.cpp)

add_library(scheduling ${SOURCES_LIB_SCHEDULING})

add_executable(main_scheduling ${SOURCES_EXE_SCHEDULING})
target_link_libraries(main_scheduling scheduling)

add_executable(TestScheduling
        $<TARGET_OBJECTS:CatchMain>
        ${SOURCES_TEST_SCHEDULING})
#target_include_directories(Test PUBLIC ${CMAKE_SOURCE_DIR}/extern)
target_link_libraries(TestScheduling)
add_test(CATCH_TestScheduling TestScheduling)
