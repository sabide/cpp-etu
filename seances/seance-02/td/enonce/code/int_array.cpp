#include "int_array.hpp"

#include <stdexcept>

void create_array(IntArray& array, int initial_capacity)
{
    if (initial_capacity < 1) {
        throw std::invalid_argument{"capacity must be positive"};
    }
    if (array.data != nullptr) {
        throw std::logic_error{"array is already initialized"};
    }

    array.data = new int[initial_capacity];
    array.capacity = initial_capacity;
    array.size = 0;
}

void push_back(IntArray& array, int value)
{
    if (array.size == array.capacity) {
        const int new_capacity{2 * array.capacity};
        int* new_data{new int[new_capacity]};

        for (int i{0}; i < array.size; ++i) {
            new_data[i] = array.data[i];
        }

        delete[] array.data;
        array.data = new_data;
        array.capacity = new_capacity;
    }

    array.data[array.size] = value;
    ++array.size;
}

int at(const IntArray& array, int index)
{
    if (index < 0 || index >= array.size) {
        throw std::out_of_range{"IntArray index out of range"};
    }
    return array.data[index];
}

int sum(const IntArray& array)
{
    int result{};
    for (int i{0}; i < array.size; ++i) {
        result += array.data[i];
    }
    return result;
}

void fill(IntArray& array, int value)
{
    for (int i{0}; i < array.size; ++i) {
        array.data[i] = value;
    }
}

void destroy_array(IntArray& array)
{
    delete[] array.data;
    array.data = nullptr;
    array.capacity = 0;
    array.size = 0;
}
