#include "Point2D.hh"
 
Point2D::Point2D()
{
    x= 0; y = 0;
} 
 
 
Point2D::Point2D(double a, double b)
{
    x= a; y = b;
} 
 
ostream& operator<<(ostream& o, const Point2D& pt)
{
    o << pt.x << " " << pt.y;
    return o;
}
