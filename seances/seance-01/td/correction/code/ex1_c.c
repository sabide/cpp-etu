#include <stdlib.h>

int main(void) {
    int n = 8;
    int* values = malloc(n * sizeof *values);
    if (values == NULL) return 1;
    free(values);
}
