#include<iostream>
#include"R2.hpp"
int main(void){
    R2 A(0,0),B(1,0),C(0,1);
    R2 AB(A,B);
    R2 AC(A,C);
    AC += AC;
    auto mes = AB^AC;
    std::cout<< AB <<  std::endl;
    std::cout<< AC <<  std::endl;
    std::cout << mes << std::endl;

    return 0; 
}