#include <iostream>

void minmax(const double* values,
            int n,
            double& minimum,
            double& maximum)
{
    minimum = values[0];
    maximum = values[0];

    // TODO : parcourir les autres valeurs et mettre a jour les deux sorties.
    (void)n;
}

int& toto(int& value)
{
    // TODO : renvoyer un alias de l'objet recu.
    return value;
}

int main()
{
    double values[]{4.5, -2.0, 8.0, 1.5, 3.0};
    double lo{};
    double hi{};
    minmax(values, 5, lo, hi);

    std::cout << "minimum = " << lo << '\n';
    std::cout << "maximum = " << hi << '\n';

    int z{4};
    toto(z) = 18;
    std::cout << "z = " << z << '\n';
    std::cout << &z << '\n';
    std::cout << &toto(z) << '\n';
}
