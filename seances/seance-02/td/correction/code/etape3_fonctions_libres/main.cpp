#include "int_array.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    IntArray values;
    create_array(values, 2);

    push_back(values, 10);
    push_back(values, 20);
    push_back(values, 7, 3);

    std::cout << "size = " << values.size << '\n';
    std::cout << "capacity = " << values.capacity << '\n';
    std::cout << "sum = " << sum(values) << '\n';

    fill(values, 4);
    std::cout << "first = " << at(values, 0) << '\n';
    std::cout << "last = " << at(values, values.size - 1) << '\n';

    try {
        push_back(values, 1, -2);
    } catch (const std::invalid_argument& error) {
        std::cout << "error = " << error.what() << '\n';
    }

    destroy_array(values);
}
