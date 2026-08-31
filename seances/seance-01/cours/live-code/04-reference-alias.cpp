#include <iostream>

int& toto(int& value)
{
    return value;
}

int main()
{
    int z{3};
    int& alias{z};

    std::cout << "avant : " << z << '\n';
    alias = 8;
    std::cout << "après alias = 8 : " << z << '\n';

    toto(z) = 18;
    std::cout << "après toto(z) = 18 : " << z << '\n';

    std::cout << "adresse de z          : " << &z << '\n';
    std::cout << "adresse via alias     : " << &alias << '\n';
    std::cout << "adresse via toto(z)   : " << &toto(z) << '\n';
}
