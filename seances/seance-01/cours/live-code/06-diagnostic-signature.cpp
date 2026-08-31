#include <iostream>

struct Point {
    double x{};
    double y{};
};

void translate(Point& point, double dx)
{
    point.x += dx;
}

int main()
{
    Point movable{1.0, 2.0};
    translate(movable, 3.0);
    std::cout << movable.x << '\n';

#ifdef TRY_MODIFY_READ_ONLY
    const Point fixed{1.0, 2.0};
    translate(fixed, 3.0);
#endif
}
