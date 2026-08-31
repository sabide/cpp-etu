#include <iostream>

int main()
{
    const int iterations{4};
    const double step{0.25};

    std::cout << "iterations = " << iterations << '\n';
    std::cout << "step = " << step << '\n';

#ifdef TRY_NARROWING
    const int invalid{3.9};
    std::cout << invalid << '\n';
#endif
}
