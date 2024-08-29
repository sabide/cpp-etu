# include <iostream>
class cmplx{
private:
    double re_,im_;
public:
    cmplx() : re_ {0} , im_ {0} {};
    cmplx(double x) : re_ {x} , im_ {0} {};
    cmplx(double x,double y) : re_ {x} , im_ {y} {};
    cmplx(const cmplx& a) : re_ { a.re_} , im_ {a.im_} { };
    ~cmplx(){ };
    const double& re() const { return re_; };
    const double& im() const { return im_; };
    double& re(){ return this->re_; };
    double& im(){ return this->im_; };
    friend void print(const cmplx&) ;

    cmplx& operator~(){ 
        //cmplx res(*this);
        //res.im()=-res.im();
        std::cout << "la" << std::endl;
        im_ = -im_;
        return *this; };

    cmplx operator+(const cmplx z) const { 
        cmplx res(*this);
        res.re() += z.re();
        res.im() += z.im();
        return res; };

};
/*
    cmplx operator~(const cmplx &z){  
        cmplx res(z);  
        std::cout << "ici" << std::endl;
        res.im()=-z.im();    
      return res;  
    } ;
*/
void print(const cmplx& a)  { std::cout << a.re() << " "<< a.im() << std::endl; };

int main(void){
    cmplx z;
    cmplx z1,z2;
    z1.re()=z2.im()=3;
    //z=~(z1+z2);
    //std::cout << (~z).im() <<std::endl;
    const cmplx z3 {1,2};
    ~z3;
    print(z3);

//    const A a2(0.,0.);
//    std::cout << a2.m() << " " << a2.n()<< std::endl;
}
