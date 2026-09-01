#include <iostream>

int main() {
    double x{2.0};
    const double y{3.0};

    double& r1{x};
    // double& r2{y};       // Erreur volontaire.
    const double& r3{y};

    r1 += 1.0;
    // r3 += 1.0;          // Erreur volontaire.

    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << r3 << '\n';
}
