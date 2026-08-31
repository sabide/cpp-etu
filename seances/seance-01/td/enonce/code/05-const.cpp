#include <iostream>

int main()
{
    double x{2.0};
    const double y{3.0};

    double& r1{x};
    const double& r3{y};

    r1 += 1.0;
    std::cout << "x = " << x << ", y = " << r3 << '\n';

#ifdef TRY_INVALID_CONST_BIND
    double& r2{y};
    std::cout << r2 << '\n';
#endif

#ifdef TRY_INVALID_CONST_WRITE
    r3 += 1.0;
#endif
}
