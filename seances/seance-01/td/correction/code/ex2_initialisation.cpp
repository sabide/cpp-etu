#include <cmath>
#include <iostream>

int main() {
    double x{};
    double y{};

    std::cout << "x ? ";
    std::cin >> x;
    std::cout << "y ? ";
    std::cin >> y;

    double moyenne{(x + y) / 2.0};
    double distance{std::abs(x - y)};

    std::cout << "moyenne = " << moyenne << '\n';
    std::cout << "distance = " << distance << '\n';
}
