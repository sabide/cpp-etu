#ifndef SEANCE6_QUADRATURE_HPP
#define SEANCE6_QUADRATURE_HPP

#include "scalar_function.hpp"

#include <cstddef>

double midpoint(const ScalarFunction& function,
                double lower,
                double upper,
                std::size_t intervals);

#endif
