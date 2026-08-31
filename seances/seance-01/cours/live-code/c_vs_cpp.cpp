#include <stdlib.h>

int main(void)
{
    int n = 10;
    int* data = malloc(n * sizeof *data);

    if (data == NULL)
        return 1;

    free(data);
}
