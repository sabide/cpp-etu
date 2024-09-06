#ifndef __ROT_HH__
#define __ROT_HH__
 
#include "Mat22.hh"
#include "Point2D.hh"
 
class Rot : public Mat22
{
    public:
        Rot(double teta);
        Point2D operator() (const Point2D& ) const;
 
 
};
 
 
#endif
