//
// Created by belse on 06.01.18.
//

#ifndef SCHEDULING_SCHEDULINGSTRATEGY_HPP
#define SCHEDULING_SCHEDULINGSTRATEGY_HPP


#include <vector>
#include <optional>
#include "Process.hpp"

class SchedulingStrategy {
public:
    virtual std::optional<size_t> next(const std::vector<Process*> &processes) = 0;
};


#endif //SCHEDULING_SCHEDULINGSTRATEGY_HPP
