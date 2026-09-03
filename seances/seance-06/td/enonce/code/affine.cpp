#include "affine.hpp"

Affine::Affine(double slope, double intercept) noexcept
    : slope_{slope}, intercept_{intercept}
{}

double Affine::operator()(double x) const noexcept
{
    return slope_ * x + intercept_;
}
