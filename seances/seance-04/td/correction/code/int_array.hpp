#ifndef SEANCE4_CORRECTION_INT_ARRAY_HPP
#define SEANCE4_CORRECTION_INT_ARRAY_HPP

#include <cstddef>

class IntArray {
public:
    explicit IntArray(std::size_t capacity);
    ~IntArray();

    IntArray(const IntArray& other);
    IntArray& operator=(const IntArray& other);
    IntArray(IntArray&& other) noexcept;
    IntArray& operator=(IntArray&& other) noexcept;

    void push_back(int value);
    int at(std::size_t index) const;
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    int sum() const;
    void fill(int value);
    std::size_t size() const;
    std::size_t capacity() const;

private:
    std::size_t capacity_{};
    std::size_t size_{};
    int* data_{nullptr};
};

#endif
