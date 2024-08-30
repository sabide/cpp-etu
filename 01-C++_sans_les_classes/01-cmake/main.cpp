#include <iomanip>
#include <iostream>

int main()
{
    std::cout << "Entre ton nom: ";
    char name[20] = "";
    std::cin >> std::setw(20) >> name;
    std::cout << " hello world !" << std::endl;

    return 0;
}