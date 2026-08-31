#include <iostream>
#include <string>

int main()
{
    const std::string a{"pressure"};
    std::string b{a};

    b += "_mean";

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "a.size() = " << a.size() << '\n';
    std::cout << std::boolalpha << "a == b : " << (a == b) << '\n';
}
