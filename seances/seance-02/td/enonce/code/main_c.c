#include "int_array_c.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    IntArrayC* values = create_array(2);
    if (values == NULL) {
        return EXIT_FAILURE;
    }

    for (int value = 1; value <= 5; ++value) {
        if (!push_back(values, value * value)) {
            destroy_array(values);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < values->size; ++i) {
        int value;
        if (at(values, i, &value)) {
            printf("%d\n", value);
        }
    }

    destroy_array(values);
    return EXIT_SUCCESS;
}
