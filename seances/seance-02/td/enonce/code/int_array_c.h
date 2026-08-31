#ifndef INT_ARRAY_C_H
#define INT_ARRAY_C_H

typedef struct {
    int capacity;
    int size;
    int* data;
} IntArrayC;

IntArrayC* create_array(int initial_capacity);
int push_back(IntArrayC* array, int value);
int at(const IntArrayC* array, int index, int* result);
void destroy_array(IntArrayC* array);

#endif
