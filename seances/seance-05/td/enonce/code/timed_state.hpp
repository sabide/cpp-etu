#ifndef SEANCE5_TIMED_STATE_HPP
#define SEANCE5_TIMED_STATE_HPP

#include "state.hpp"

#include <cstddef>

class TimedState : public State {
public:
    TimedState(std::size_t dimension, double time);

    double time() const noexcept;
    double first() const;

private:
    double time_{};
};

#endif
