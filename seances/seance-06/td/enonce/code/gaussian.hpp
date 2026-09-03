#ifndef SEANCE6_GAUSSIAN_HPP
#define SEANCE6_GAUSSIAN_HPP

#include "scalar_function.hpp"

class Gaussian final : public ScalarFunction {
public:
    explicit Gaussian(double sigma);
    double operator()(double x) const noexcept override;

private:
    double sigma_{1.0};
};

#endif
