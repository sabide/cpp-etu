#include "quadrilateral.hpp"

Quadrilateral::Quadrilateral(int id, double area)
    : Element{id}, area_{area}
{}

double Quadrilateral::area() const
{
    return area_;
}
