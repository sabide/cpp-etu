#ifndef SEANCE6_SCALAR_FUNCTION_HPP
#define SEANCE6_SCALAR_FUNCTION_HPP

class ScalarFunction {
public:
    virtual double operator()(double x) const = 0;
    virtual ~ScalarFunction() = default;
};

#endif
