#ifndef SEANCE6_AFFINE_HPP
#define SEANCE6_AFFINE_HPP

#include "scalar_function.hpp"

class Affine final : public ScalarFunction {
public:
    Affine(double slope, double intercept) noexcept;
    double operator()(double x) const noexcept override;

private:
    double slope_{};
    double intercept_{};
};

#endif
