#include "affine.hpp"
#include "gaussian.hpp"
#include "quadrature.hpp"
#include "sine.hpp"

#include <iostream>

namespace {
void show(const ScalarFunction& function, const char* name)
{
    std::cout << name << "(0.5) = " << function(0.5)
              << ", integral = " << midpoint(function, 0.0, 1.0, 1000)
              << '\n';
}
}

int main()
{
    const Affine affine{1.0, 0.0};
    const Gaussian gaussian{0.5};
    const Sine sine{};

    show(affine, "affine");
    show(gaussian, "gaussian");
    show(sine, "sine");
}
