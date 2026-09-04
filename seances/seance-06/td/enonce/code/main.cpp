#include "quadrilateral.hpp"
#include "report.hpp"
#include "triangle.hpp"

#include <iostream>
#include <vector>

int main()
{
    const Triangle triangle{7, 2.5};
    const Quadrilateral quadrilateral{8, 4.0};

    std::cout << "appel direct : " << triangle.area() << '\n';

    const Element& element{triangle};
    std::cout << "via Element& : " << element.area() << '\n';

    const std::vector<const Element*> elements{
        &triangle,
        &quadrilateral
    };

    for (const Element* current : elements) {
        report(*current);
    }
    std::cout << "aire totale = " << total_area(elements) << '\n';
}
