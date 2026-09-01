#include "int_array.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

int main()
{
    IntArray values;
    create_array(values, 2);

    values.push_back(10);
    values.push_back(20);
    assert(values.size == 2);
    assert(values.capacity == 2);

    values.push_back(30);
    assert(values.size == 3);
    assert(values.capacity == 4);
    assert(values.at(0) == 10);
    assert(values.at(2) == 30);

    values.push_back(40, 6);
    assert(values.size == 9);
    assert(values.capacity == 16);
    assert(values.at(0) == 10);
    assert(values.at(values.size - 1) == 40);

    std::cout << "sum before fill = " << values.sum() << '\n';

    values.fill(7);
    assert(values.size == 9);
    assert(values.capacity == 16);
    assert(values.sum() == 63);

    try {
        values.at(-1);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "index -1 refused\n";
    }

    try {
        values.at(values.size);
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "index size refused\n";
    }

    destroy_array(values);
    assert(values.size == 0);
    assert(values.capacity == 0);
    assert(values.data == nullptr);
}
