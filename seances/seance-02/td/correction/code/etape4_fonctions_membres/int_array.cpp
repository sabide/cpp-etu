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

    array.data = new int[initial_capacity]{};
    array.capacity = initial_capacity;
    array.size = 0;
}

void IntArray::push_back(int value)
{
    if (size == capacity) {
        const int new_capacity{2 * capacity};
        int* new_data{new int[new_capacity]{}};

        for (int i{0}; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    ++size;
}

void IntArray::push_back(int value, int repetitions)
{
    if (repetitions < 0) {
        throw std::invalid_argument{"repetitions must be non-negative"};
    }

    for (int i{0}; i < repetitions; ++i) {
        push_back(value);
    }
}

int IntArray::at(int index) const
{
    if (index < 0 || index >= size) {
        throw std::out_of_range{"IntArray index out of range"};
    }
    return data[index];
}

int IntArray::sum() const
{
    int result{};
    for (int i{0}; i < size; ++i) {
        result += data[i];
    }
    return result;
}

void IntArray::fill(int value)
{
    for (int i{0}; i < size; ++i) {
        data[i] = value;
    }
}

void destroy_array(IntArray& array)
{
    delete[] array.data;
    array.data = nullptr;
    array.capacity = 0;
    array.size = 0;
}
