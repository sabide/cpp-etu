#include <cmath>
#include <iostream>

struct Point {
    double x{};
    double y{};
};

double norm(const Point& point)
{
    return std::sqrt(point.x * point.x + point.y * point.y);
}

void translate(Point& point, double dx, double dy)
{
    point.x += dx;
    point.y += dy;
}

Point translated(Point point, double dx, double dy)
{
    translate(point, dx, dy);
    return point;
}

int main()
{
    Point point{3.0, 4.0};
    std::cout << "norme = " << norm(point) << '\n';

    const Point copy{translated(point, 1.0, -2.0)};
    std::cout << "original : " << point.x << ", " << point.y << '\n';
    std::cout << "copie    : " << copy.x << ", " << copy.y << '\n';

    translate(point, -1.0, 2.0);
    std::cout << "modifié  : " << point.x << ", " << point.y << '\n';
}
