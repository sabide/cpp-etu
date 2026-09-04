#include "report.hpp"

#include <iostream>

void report(const Element& element)
{
    std::cout << "element " << element.id()
              << " : aire = " << element.area() << '\n';
}

double total_area(const std::vector<const Element*>& elements)
{
    double total{};
    for (const Element* element : elements) {
        total += element->area();
    }
    return total;
}
