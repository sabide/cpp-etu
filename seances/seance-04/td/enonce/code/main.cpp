#include "int_array.hpp"

#include <cassert>
#include <iostream>

int main()
{
    IntArray values{2};
    values.push_back(1);
    values.push_back(4);
    values.push_back(9);

    assert(values.size() == 3);
    assert(values.at(2) == 9);
    assert(values.sum() == 14);

    std::cout << "starter OK\n";
}
