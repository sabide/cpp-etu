# include <iostream>
class A{
    public:
       int nb_acces_;
private:
    double m_,n_;
public:
    A(){++nb_acces_;std::cout << "cons 0 " << this <<std::endl;};
    A(double m) : m_ {m} {std::cout << "cons 1 " << this <<std::endl;};
    A(double m,double n) : m_ {m}, n_ {n} {std::cout << "cons 2 " << this <<std::endl;};
    A(const A& a) : m_ {a.m_} , n_ {a.n_} {std::cout << "cons 3 " << this <<std::endl;};
    ~A(){ std::cout << "dest  " << this <<std::endl;};
    const double& m() const { 
        //++(const_cast<int >(nb_acces_));
        A* ptr = const_cast<A* >(this);
        ++(ptr->nb_acces_);
        return (const_cast<A* >(this))->m_; };
    const double& n() const { return this->n_; };
    double& m(){ return this->m_; };
    double& n(){ return this->n_; };

    friend void print(const A&) ;
};
void print(const A& a)  { std::cout << a.m_ << " "<< a.n_ << std::endl; };

void f(A a)  { print(a) ; };

int main(void){
    A a1;
    a1.m()=a1.n()=3;
    print(a1);
    const A a2(0.,0.);
    std::cout << a2.m() << " " << a2.n()<< std::endl;
}
