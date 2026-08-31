#include <iostream>

struct IntArray {
    int capacity{};
    int size{};
    int* data{nullptr};
};

void create_array(IntArray& array, int initial_capacity)
{
    array.capacity = initial_capacity;
    array.size = 0;
    array.data = new int[initial_capacity]{};
}

void push_back(IntArray& values, int value)
{
    if (values.size < values.capacity) {
        values.data[values.size] = value;
        ++values.size;
    }
}

int at(const IntArray& values, int index)
{
    return values.data[index];
}

void destroy_array(IntArray& array)
{
    delete[] array.data;
    array.data = nullptr;
    array.capacity = 0;
    array.size = 0;
}

int main()
{
    IntArray values;
    create_array(values, 4);

    push_back(values, 7);
    push_back(values, 12);

    std::cout << "size = " << values.size << '\n';
    std::cout << "values[1] = " << at(values, 1) << '\n';

    destroy_array(values);
}
