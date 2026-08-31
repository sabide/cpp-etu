#include <cstddef>
#include <iostream>

struct IntArray {
    std::size_t capacity{};
    std::size_t size{};
    int* data{nullptr};

    void push_back(int value)
    {
        if (size < capacity) {
            data[size] = value;
            ++size;
        }
    }

    int at(std::size_t index) const
    {
        return data[index];
    }
};

int main()
{
    int storage[4]{};
    IntArray values{4, 0, storage};

    values.push_back(7);
    values.push_back(12);
    std::cout << values.at(1) << '\n';
}
