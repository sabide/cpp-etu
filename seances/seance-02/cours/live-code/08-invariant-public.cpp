#include <cstddef>
#include <iostream>

struct IntArray {
    std::size_t capacity{};
    std::size_t size{};
    int* data{nullptr};
};

int main()
{
    int storage[2]{};
    IntArray values{2, 0, storage};

    values.size = 10;
    values.capacity = 2;

    std::cout << "size = " << values.size << '\n';
    std::cout << "capacity = " << values.capacity << '\n';
    std::cout << "size <= capacity : " << std::boolalpha
              << (values.size <= values.capacity) << '\n';
}
