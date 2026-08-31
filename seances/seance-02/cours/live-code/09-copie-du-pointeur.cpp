#include <cstddef>
#include <iostream>

struct IntArray {
    std::size_t capacity{};
    std::size_t size{};
    int* data{nullptr};
};

int main()
{
    int storage[2]{42, 7};
    IntArray a{2, 2, storage};
    IntArray b{a};

    std::cout << "a.data = " << static_cast<void*>(a.data) << '\n';
    std::cout << "b.data = " << static_cast<void*>(b.data) << '\n';

    b.data[0] = 0;
    std::cout << "a.data[0] = " << a.data[0] << '\n';
    std::cout << "b.data[0] = " << b.data[0] << '\n';
}
