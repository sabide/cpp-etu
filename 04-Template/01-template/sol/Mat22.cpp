#include "Mat22.hh"
 
 
Mat22::Mat22()
{
    _m[0][0] = 0;
    _m[0][1] = 0;
    _m[1][0] = 0;
    _m[1][1] = 0;
}
 
void Mat22::setM(const double tab[2][2])
{
    _m[0][0] = tab[0][0];
    _m[1][0] = tab[1][0];
    _m[0][1] = tab[0][1];
    _m[1][1] = tab[1][1];
}
 
 
 
double* Mat22::operator[](int i)
{
    return _m[i];
}
 
ostream& operator<<(ostream& o, Mat22& m)
{
     o << m[0][0] << "\t" << m[0][1] << endl;
     o << m[1][0] << "\t" << m[1][1] << endl;
     return o;
}
