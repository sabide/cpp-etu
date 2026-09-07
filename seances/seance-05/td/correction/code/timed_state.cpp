#include "timed_state.hpp"

TimedState::TimedState(std::size_t dimension, double time)
    : State{dimension}, time_{time}
{}

double TimedState::time() const noexcept
{
    return time_;
}

double TimedState::first() const
{
    return (*this)[0];
}
