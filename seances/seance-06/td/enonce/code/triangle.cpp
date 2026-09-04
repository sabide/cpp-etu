#include "triangle.hpp"

Triangle::Triangle(int id, double area)
    : Element{id}, area_{area}
{}

double Triangle::area() const
{
    return area_;
}
