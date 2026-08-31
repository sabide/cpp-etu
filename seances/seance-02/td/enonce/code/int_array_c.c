#include "int_array_c.h"

#include <stdlib.h>

IntArrayC* create_array(int initial_capacity)
{
    if (initial_capacity < 1) {
        return NULL;
    }

    IntArrayC* array = malloc(sizeof *array);
    if (array == NULL) {
        return NULL;
    }

    array->data = malloc((size_t)initial_capacity * sizeof *array->data);
    if (array->data == NULL) {
        free(array);
        return NULL;
    }

    array->capacity = initial_capacity;
    array->size = 0;
    return array;
}

int push_back(IntArrayC* array, int value)
{
    if (array == NULL) {
        return 0;
    }

    if (array->size == array->capacity) {
        const int new_capacity = 2 * array->capacity;
        int* new_data = realloc(
            array->data,
            (size_t)new_capacity * sizeof *array->data
        );
        if (new_data == NULL) {
            return 0;
        }
        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size] = value;
    ++array->size;
    return 1;
}

int at(const IntArrayC* array, int index, int* result)
{
    if (array == NULL || result == NULL || index < 0 || index >= array->size) {
        return 0;
    }
    *result = array->data[index];
    return 1;
}

void destroy_array(IntArrayC* array)
{
    if (array == NULL) {
        return;
    }
    free(array->data);
    free(array);
}
