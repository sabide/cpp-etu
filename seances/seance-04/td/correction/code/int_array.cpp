#include "int_array.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace {
std::size_t checked_capacity(std::size_t capacity)
{
    if (capacity == 0) {
        throw std::invalid_argument{"capacity must be positive"};
    }
    return capacity;
}
}

IntArray::IntArray(std::size_t capacity)
    : capacity_{checked_capacity(capacity)},
      size_{0},
      data_{new int[capacity_] {}}
{
}

IntArray::~IntArray()
{
    delete[] data_;
}

IntArray::IntArray(const IntArray& other)
    : capacity_{other.capacity_},
      size_{other.size_},
      data_{capacity_ == 0 ? nullptr : new int[capacity_]}
{
    if (size_ > 0) {
        std::copy_n(other.data_, size_, data_);
    }
}

IntArray& IntArray::operator=(const IntArray& other)
{
    if (this == &other) {
        return *this;
    }

    int* new_data{
        other.capacity_ == 0 ? nullptr : new int[other.capacity_]};
    if (other.size_ > 0) {
        std::copy_n(other.data_, other.size_, new_data);
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = other.capacity_;
    size_ = other.size_;
    return *this;
}

IntArray::IntArray(IntArray&& other) noexcept
    : capacity_{std::exchange(other.capacity_, 0)},
      size_{std::exchange(other.size_, 0)},
      data_{std::exchange(other.data_, nullptr)}
{
}

IntArray& IntArray::operator=(IntArray&& other) noexcept
{
    if (this != &other) {
        delete[] data_;
        capacity_ = std::exchange(other.capacity_, 0);
        size_ = std::exchange(other.size_, 0);
        data_ = std::exchange(other.data_, nullptr);
    }
    return *this;
}

void IntArray::push_back(int value)
{
    if (size_ == capacity_) {
        const std::size_t new_capacity{capacity_ == 0 ? 1 : 2 * capacity_};
        int* new_data{new int[new_capacity] {}};
        if (size_ > 0) {
            std::copy_n(data_, size_, new_data);
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

int& IntArray::operator[](std::size_t index)
{
    return data_[index];
}

const int& IntArray::operator[](std::size_t index) const
{
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
    std::fill_n(data_, size_, value);
}

std::size_t IntArray::size() const
{
    return size_;
}

std::size_t IntArray::capacity() const
{
    return capacity_;
}
