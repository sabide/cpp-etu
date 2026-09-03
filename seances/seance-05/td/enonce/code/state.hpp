#ifndef SEANCE5_STATE_HPP
#define SEANCE5_STATE_HPP

#include <cstddef>
#include <vector>

class State {
public:
    explicit State(std::size_t dimension, double initial_value = 0.0);

    double& operator[](std::size_t index);
    const double& operator[](std::size_t index) const;
    double& at(std::size_t index);
    const double& at(std::size_t index) const;

    std::size_t size() const noexcept;
    void fill(double value) noexcept;

private:
    std::vector<double> values_;
};

double l2_norm(const State& state);
void scale(State& state, double factor) noexcept;

#endif
