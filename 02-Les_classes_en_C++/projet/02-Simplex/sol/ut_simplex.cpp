#include<iostream>
#include"Simplex.hpp"
int main(void){
    R2 A(0,0),B(1,0),C(0,1);
    R2 AB(A,B);
    R2 AC(A,C);
    AC += AC;
    auto mes = AB^AC;
    std::cout<< AB <<  std::endl;
    std::cout<< AC <<  std::endl;
    std::cout << mes << std::endl;

    Vertex n1;
    //std::cin >> n1 ;
    std::cout << n1 << std::endl;
    Simplex t1;
    t1[0] = A ;
    t1[1] = B ;
    t1[2] = C ;
    std::cout << t1 ;

    



    return 0; 
}