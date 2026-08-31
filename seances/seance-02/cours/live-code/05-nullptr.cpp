#include <iostream>

void inspect(int)
{
    std::cout << "inspect(int)\n";
}

void inspect(double*)
{
    std::cout << "inspect(double*)\n";
}

int main()
{
    inspect(0);
    inspect(nullptr);
}
