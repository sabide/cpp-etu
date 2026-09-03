#ifndef SEANCE6_SINE_HPP
#define SEANCE6_SINE_HPP
#include "scalar_function.hpp"
#include <cmath>
class Sine final : public ScalarFunction { public: double operator()(double x) const noexcept override; };
#endif
