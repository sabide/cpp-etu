#include <iostream>

void inspect(int value)
{
    std::cout << "inspect(int): " << value << '\n';
}

void inspect(double* values)
{
    std::cout << "inspect(double*): " << values << '\n';
}

int main()
{
    // TODO : predire quelle fonction est choisie pour chaque appel.
    inspect(0);
    inspect(nullptr);
}
