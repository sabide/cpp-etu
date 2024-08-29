# include <iostream>
class A{
private:
    double m_,n_;
public:
    A(){std::cout << "cons 0 " << this <<std::endl;};
    A(double m) : m_ {m} {std::cout << "cons 1 " << this <<std::endl;};
    A(double m,double n) : m_ {m}, n_ {n} {std::cout << "cons 2 " << this <<std::endl;};
    A(const A& a) : m_ {a.m_} , n_ {a.n_} {std::cout << "cons 3 " << this <<std::endl;};
    ~A(){ std::cout << "dest  " << this <<std::endl;};
    void set(double m){ this->m_=m; };
    double get(){ return this->m_; };
    void qui_suis_je(){ std::cout << this << std::endl; };
    friend void print(const A&) ;
};
void print(const A& a)  { std::cout << a.m_ << " "<< a.n_ << std::endl; };

void f(A a)  { print(a) ; };

int main(void){
    A a1 (1.);
    A a2 (1.,2.);
    const double x=1.0,y=2.0;
    A a3 (x,y);
    print(a3);
    f(a3);    
}