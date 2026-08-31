#include <cmath>
#include <iostream>

int main()
{
    double x{};
    double y{};

    std::cout << "x ? ";
    std::cin >> x;
    std::cout << "y ? ";
    std::cin >> y;

    // TODO : calculer la moyenne et la distance entre x et y.
    const double moyenne{};
    const double distance{};

    std::cout << "moyenne = " << moyenne << '\n';
    std::cout << "distance = " << distance << '\n';

#ifdef TRY_NARROWING
    int a = 2.9;
    int b{2.9};
    std::cout << a << b << '\n';
#endif
}
