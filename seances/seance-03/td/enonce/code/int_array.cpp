#include "int_array.hpp"

#include <stdexcept>

void IntArray::initialize(std::size_t initial_capacity)
{
    if (initial_capacity == 0) {
        throw std::invalid_argument{"capacity must be positive"};
    }
    if (data != nullptr) {
        throw std::logic_error{"array is already initialized"};
    }

    data = new int[initial_capacity]{};
    capacity = initial_capacity;
    size = 0;
}

void IntArray::destroy()
{
    delete[] data;
    data = nullptr;
    capacity = 0;
    size = 0;
}

void IntArray::push_back(int value)
{
    if (data == nullptr) {
        throw std::logic_error{"array is not initialized"};
    }

    if (size == capacity) {
        const std::size_t new_capacity{2 * capacity};
        int* new_data{new int[new_capacity]};

        for (std::size_t i{0}; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    ++size;
}

int IntArray::at(std::size_t index) const
{
    if (index >= size) {
        throw std::out_of_range{"IntArray index out of range"};
    }
    return data[index];
}

int IntArray::sum() const
{
    int result{};
    for (std::size_t i{0}; i < size; ++i) {
        result += data[i];
    }
    return result;
}

void IntArray::fill(int value)
{
    for (std::size_t i{0}; i < size; ++i) {
        data[i] = value;
    }
}
