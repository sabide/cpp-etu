#include "polynome.h"
bool polynome::printMonome(std::ostream& os, double a, int deg) const {
  bool monomeNull = true ; 
  if (a != 0.0)
    {
      os << ( (a<0) ? '-' : '+' ) ; // signe du monome
      if (a<0.0) a = -a ;
      if (a !=1 || deg==0 ) os<< a ;
      if ( deg >0 ) os << 'x' ;
      if ( deg >1 ) os << '^' << deg ;
    }
  return monomeNull ;
}

void polynome::print(std::ostream& stream) const {
  for(int i=0;i<this->deg_max_;++i)
    printMonome(stream, this->coeffs_[i],i);
  std::cout << std::endl;
}
//polynome::polynome(){}

 void polynome::initZero(){
  for(int i=0;i<this->deg_max_;++i)
    coeffs_[i]=0;

 };