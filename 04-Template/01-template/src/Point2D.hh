#ifndef __POINT2D_HH__
#define __POINT2D_HH__
 
#include <iostream>
 
using namespace std;
 
struct Point2D
{
    double x;
    double y;
 
    Point2D();
    Point2D(double a, double b);
};
 
ostream& operator<<(ostream & o , const Point2D& pt);
 
#endif
