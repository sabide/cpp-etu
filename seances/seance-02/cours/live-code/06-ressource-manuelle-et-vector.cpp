#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    const std::size_t n{4};

    double* manual{new double[n]{}};
    manual[0] = 3.14;
    std::cout << "tableau manuel : " << manual[0] << '\n';
    delete[] manual;

    std::vector<double> automatic(n, 0.0);
    automatic[0] = 3.14;
    std::cout << "vector : " << automatic[0] << '\n';
}
