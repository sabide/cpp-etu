#include "gaussian.hpp"

#include <cmath>
#include <stdexcept>

namespace {
double checked_sigma(double sigma)
{
    if (sigma <= 0.0) {
        throw std::invalid_argument{"sigma must be positive"};
    }
    return sigma;
}
}

Gaussian::Gaussian(double sigma)
    : sigma_{checked_sigma(sigma)}
{}

double Gaussian::operator()(double x) const noexcept
{
    const double scaled{x / sigma_};
    return std::exp(-0.5 * scaled * scaled);
}
