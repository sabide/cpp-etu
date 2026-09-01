#include <cassert>
#include <iostream>

int& toto(int& value)
{
    return value;
}

int main()
{
    int z{4};
    toto(z) = 18;

    assert(z == 18);
    assert(&toto(z) == &z);
    std::cout << "z = " << z << '\n';
}
