#include "int_array.hpp"

#include <cassert>
#include <iostream>
#include <stdexcept>

void test_early_return(bool stop)
{
    IntArray values{4};
    if (stop) {
        return;
    }
    values.push_back(3);
}

void test_exception()
{
    IntArray values{4};
    values.push_back(7);
    throw std::runtime_error{"sortie par exception"};
}

int main()
{
    IntArray values{2};
    values.push_back(1);
    values.push_back(4);
    values.push_back(9);

    assert(values.size() == 3);
    assert(values.capacity() == 4);
    assert(values.at(0) == 1);
    assert(values.at(2) == 9);
    assert(values.sum() == 14);

    values.fill(5);
    assert(values.sum() == 15);

    const IntArray& observed{values};
    assert(observed.size() == 3);
    assert(observed.capacity() == 4);
    assert(observed.at(1) == 5);

    bool invalid_capacity_detected{false};
    try {
        IntArray impossible{0};
    } catch (const std::invalid_argument&) {
        invalid_capacity_detected = true;
    }
    assert(invalid_capacity_detected);

    test_early_return(true);
    test_early_return(false);

    try {
        test_exception();
    } catch (const std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }

    std::cout << "Tous les tests de la séance 3 réussissent.\n";
}
