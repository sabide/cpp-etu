int main() {
    int n{8};
    int* values{new int[n]};

    values[0] = 42;

    delete[] values;
}
