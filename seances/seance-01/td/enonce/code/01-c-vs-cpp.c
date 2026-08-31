#include <stdlib.h>

int main(void)
{
    int n = 8;
    int* values = malloc((size_t)n * sizeof *values);
    if (values == NULL) {
        return 1;
    }

    values[0] = 42;
    free(values);
}
