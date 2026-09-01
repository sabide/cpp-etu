#include <iostream>

void minmax(const double* values,
            int n,
            double& minimum,
            double& maximum) {
    minimum = values[0];
    maximum = values[0];

    for (int i{1}; i < n; ++i) {
        if (values[i] < minimum) {
            minimum = values[i];
        }

        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
}

int main() {
    double values[]{4.5, -2.0, 8.0, 1.5, 3.0};
    int n{5};
    double lo{};
    double hi{};

    minmax(values, n, lo, hi);

    std::cout << "minimum = " << lo << '\n';
    std::cout << "maximum = " << hi << '\n';

    double x{3.0};
    double& r{x};
    r = 7.0;
    std::cout << "x = " << x << '\n';
}
