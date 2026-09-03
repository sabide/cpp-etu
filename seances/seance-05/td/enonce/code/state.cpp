#include "state.hpp"

#include <cmath>

State::State(std::size_t dimension, double initial_value)
    : values_(dimension, initial_value)
{}

double& State::operator[](std::size_t index)
{
    return values_[index];
}

const double& State::operator[](std::size_t index) const
{
    return values_[index];
}

double& State::at(std::size_t index)
{
    return values_.at(index);
}

const double& State::at(std::size_t index) const
{
    return values_.at(index);
}

std::size_t State::size() const noexcept
{
    return values_.size();
}

void State::fill(double value) noexcept
{
    for (double& entry : values_) {
        entry = value;
    }
}

double l2_norm(const State& state)
{
    double squared_norm{};
    for (std::size_t i{}; i < state.size(); ++i) {
        squared_norm += state[i] * state[i];
    }
    return std::sqrt(squared_norm);
}

void scale(State& state, double factor) noexcept
{
    for (std::size_t i{}; i < state.size(); ++i) {
        state[i] *= factor;
    }
}
