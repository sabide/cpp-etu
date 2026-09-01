#include <iostream>
#include <string>
#include <vector>

struct Sample {
    std::string name;
    std::vector<double> values;
};

double mean(const Sample& s) {
    double sum{};

    for (double value : s.values) {
        sum += value;
    }

    return sum / static_cast<double>(s.values.size());
}

void center(Sample& s) {
    double m{mean(s)};

    for (double& value : s.values) {
        value -= m;
    }
}

void print(const Sample& s) {
    std::cout << s.name << " :";

    for (double value : s.values) {
        std::cout << ' ' << value;
    }

    std::cout << '\n';
}

double square(double x) {
    return x * x;
}

void multiply_by_two(double& x) {
    x *= 2.0;
}

int main() {
    Sample s{"test", {2.0, 4.0, 6.0}};

    print(s);
    std::cout << "moyenne = " << mean(s) << '\n';

    center(s);
    print(s);

    double x{5.0};
    std::cout << "square(x) = " << square(x) << '\n';
    multiply_by_two(x);
    std::cout << "x = " << x << '\n';
}
