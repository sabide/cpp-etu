#include <iostream>
#include "polynome.h"


void f(polynome q){
  q.print( std::cout );
}

int main(void){
  
  polynome p1(10,1,0,1,1) ;
  
  p1.print( std::cout );
  //f(p1);

  double& coeff = p1.get(0);
 
  std::cout << &coeff <<" "<< p1.get_data() <<std::endl ; 
  coeff = 3;
  p1.print( std::cout );
  //const  polynome p2(0,1,0,1,1);
  ///f(p1);


}
