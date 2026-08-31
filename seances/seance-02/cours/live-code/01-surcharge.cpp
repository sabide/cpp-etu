#include <cmath>
#include <iostream>

double norm(double x)
{
    return std::abs(x);
}

double norm(double x, double y)
{
    return std::sqrt(x * x + y * y);
}

int main()
{
    std::cout << "norm(-3.0) = " << norm(-3.0) << '\n';
    std::cout << "norm(3.0, 4.0) = " << norm(3.0, 4.0) << '\n';
}
