#include "affine.hpp"
#include "gaussian.hpp"
#include "quadrature.hpp"
#include "sine.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

int main()
{
    const Affine identity{1.0, 0.0};
    const Affine constant{0.0, 2.0};
    const Gaussian gaussian{0.5};
    const Sine sine{};

    assert(std::abs(midpoint(identity, 0.0, 1.0, 1000) - 0.5) < 1.0e-12);
    assert(std::abs(midpoint(constant, 0.0, 3.0, 10) - 6.0) < 1.0e-12);
    assert(gaussian(0.0) == 1.0);

    const double pi{std::acos(-1.0)};
    assert(std::abs(midpoint(sine, 0.0, pi, 20000) - 2.0) < 1.0e-6);
    std::cout << midpoint(identity, 0.0, 1.0, 1000) << ' '
              << midpoint(gaussian, 0.0, 1.0, 1000) << ' '
              << midpoint(sine, 0.0, 1.0, 1000) << '\n';
}
