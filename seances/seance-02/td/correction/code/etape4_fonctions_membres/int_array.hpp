#ifndef INT_ARRAY_ETAPE4_HPP
#define INT_ARRAY_ETAPE4_HPP

struct IntArray {
    int capacity{};
    int size{};
    int* data{nullptr};

    void push_back(int value);
    void push_back(int value, int repetitions);
    int at(int index) const;
    int sum() const;
    void fill(int value);
};

void create_array(IntArray& array, int initial_capacity);
void destroy_array(IntArray& array);

#endif
