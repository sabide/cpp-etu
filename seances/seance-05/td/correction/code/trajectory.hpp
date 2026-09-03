#ifndef SEANCE5_TRAJECTORY_HPP
#define SEANCE5_TRAJECTORY_HPP

#include "timed_state.hpp"

#include <cstddef>
#include <vector>

class Trajectory {
public:
    void append(TimedState state);
    const TimedState& at(std::size_t index) const;
    std::size_t size() const noexcept;

private:
    std::vector<TimedState> states_;
};

#endif
