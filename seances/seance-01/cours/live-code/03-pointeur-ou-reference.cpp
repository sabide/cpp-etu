#include <iostream>

void add_one_pointer(int* value)
{
    if (value != nullptr) {
        ++(*value);
    }
}

void add_one_reference(int& value)
{
    ++value;
}

int main()
{
    int first{3};
    int second{3};

    add_one_pointer(&first);
    add_one_pointer(nullptr);
    add_one_reference(second);

    std::cout << "pointeur : " << first << '\n';
    std::cout << "référence : " << second << '\n';
}
