#include "element.hpp"
#include "quadrilateral.hpp"
#include "report.hpp"
#include "triangle.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main()
{
    const Triangle triangle{7, 2.5};
    const Quadrilateral quadrilateral{8, 4.0};

    const Element& element{triangle};
    assert(element.id() == 7);
    assert(element.area() == 2.5);

    const std::vector<const Element*> elements{
        &triangle,
        &quadrilateral
    };

    assert(total_area(elements) == 6.5);

    for (const Element* current : elements) {
        report(*current);
    }
    std::cout << "aire totale = " << total_area(elements) << '\n';
}
