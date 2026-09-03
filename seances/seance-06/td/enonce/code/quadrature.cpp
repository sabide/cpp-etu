#include "quadrature.hpp"

#include <stdexcept>

double midpoint(const ScalarFunction& function,
                double lower,
                double upper,
                std::size_t intervals)
{
    if (intervals == 0) {
        throw std::invalid_argument{"interval count must be positive"};
    }

    const double step{(upper - lower) / static_cast<double>(intervals)};
    double sum{};
    for (std::size_t i{}; i < intervals; ++i) {
        sum += function(lower + (static_cast<double>(i) + 0.5) * step);
    }
    return step * sum;
}
