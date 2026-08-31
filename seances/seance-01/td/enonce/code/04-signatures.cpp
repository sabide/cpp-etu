#include <iostream>
#include <string>
#include <vector>

struct Sample {
    std::string name;
    std::vector<double> values;
};

// TODO : verifier les signatures, puis completer les cinq fonctions.
double mean(const Sample& sample)
{
    (void)sample;
    return 0.0;
}

void center(Sample& sample)
{
    (void)sample;
}

void print(const Sample& sample)
{
    std::cout << sample.name << '\n';
}

double square(double value)
{
    return value;
}

void multiply_by_two(double& value)
{
    (void)value;
}

int main()
{
    Sample sample{"test", {2.0, 4.0, 6.0}};
    print(sample);
    std::cout << "moyenne = " << mean(sample) << '\n';
    center(sample);
    print(sample);

    double value{5.0};
    std::cout << square(value) << '\n';
    multiply_by_two(value);
    std::cout << value << '\n';
}
