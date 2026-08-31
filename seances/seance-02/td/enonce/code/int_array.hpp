#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

struct IntArray {
    int capacity{};
    int size{};
    int* data{nullptr};
};

void create_array(IntArray& array, int initial_capacity);
void push_back(IntArray& array, int value);
int at(const IntArray& array, int index);
int sum(const IntArray& array);
void fill(IntArray& array, int value);
void destroy_array(IntArray& array);

#endif
