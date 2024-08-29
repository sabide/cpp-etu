#include <iostream>
#include "polynome.h"


void f(polynome q){
  q.print( std::cout );
}

int main(void){
  
  polynome p1(0,1,0,1,1) ;
  
  p1.print( std::cout );
  //print(&p1, cout );
  f(p1);

  //p2.print( std::cout );
  const  polynome p2(0,1,0,1,1);
  f(p2);


}
