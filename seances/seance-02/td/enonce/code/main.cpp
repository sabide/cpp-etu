#include "int_array.hpp"

#include <iostream>

int main()
{
    IntArray values;
    create_array(values, 2);

    for (int value{1}; value <= 5; ++value) {
        push_back(values, value * value);
    }

    std::cout << "sum = " << sum(values) << '\n';
    for (int i{0}; i < values.size; ++i) {
        std::cout << at(values, i) << '\n';
    }

    destroy_array(values);
}
