#include <cstdio>
#include <string>

void print_label(const char* label)
{
    std::printf("API C : %s\n", label);
}

int main()
{
    const std::string label{"pressure_mean"};
    print_label(label.c_str());
}
