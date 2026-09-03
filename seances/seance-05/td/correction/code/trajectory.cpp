#include "trajectory.hpp"

#include <stdexcept>
#include <utility>

void Trajectory::append(TimedState state)
{
    if (!states_.empty() && state.time() <= states_.back().time()) {
        throw std::invalid_argument{"times must be strictly increasing"};
    }
    states_.push_back(std::move(state));
}

const TimedState& Trajectory::at(std::size_t index) const
{
    return states_.at(index);
}

std::size_t Trajectory::size() const noexcept
{
    return states_.size();
}
