#include "int_array.hpp"

#include <stdexcept>

namespace {

std::size_t checked_capacity(std::size_t capacity)
{
    if (capacity == 0) {
        throw std::invalid_argument{"capacity must be positive"};
    }
    return capacity;
}

} // namespace

IntArray::IntArray(std::size_t capacity)
    : capacity_{checked_capacity(capacity)},
      size_{0},
      data_{new int[capacity_]{}}
{
}

IntArray::~IntArray()
{
    delete[] data_;
}

void IntArray::push_back(int value)
{
    if (size_ == capacity_) {
        const std::size_t new_capacity{capacity_ == 0 ? 1 : 2 * capacity_};
        int* new_data{new int[new_capacity]};

        for (std::size_t i{0}; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    data_[size_] = value;
    ++size_;
}

int IntArray::at(std::size_t index) const
{
    if (index >= size_) {
        throw std::out_of_range{"IntArray index out of range"};
    }
    return data_[index];
}

int IntArray::sum() const
{
    int result{};
    for (std::size_t i{0}; i < size_; ++i) {
        result += data_[i];
    }
    return result;
}

void IntArray::fill(int value)
{
    for (std::size_t i{0}; i < size_; ++i) {
        data_[i] = value;
    }
}

std::size_t IntArray::size() const
{
    return size_;
}

std::size_t IntArray::capacity() const
{
    return capacity_;
}
