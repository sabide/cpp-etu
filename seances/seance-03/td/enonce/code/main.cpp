#include "int_array.hpp"

#include <cassert>
#include <iostream>

int main()
{
    IntArray values;
    values.initialize(2);

    values.push_back(1);
    values.push_back(4);
    values.push_back(9);

    assert(values.size == 3);
    assert(values.capacity == 4);
    assert(values.at(0) == 1);
    assert(values.at(2) == 9);
    assert(values.sum() == 14);

    std::cout << "size = " << values.size << '\n';
    std::cout << "capacity = " << values.capacity << '\n';
    std::cout << "sum = " << values.sum() << '\n';

    values.destroy();
}
