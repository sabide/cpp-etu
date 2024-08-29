# include <iostream>

class A{
private:
    double m_;
public:
    void set(double m){ this->m_=m; };
    double get(){ return this->m_; };
    void qui_suis_je(){ std::cout << this << std::endl; };
    friend void print(const A&) ;
    friend class B;
};

void print(const A& a)  { std::cout << a.m_ << std::endl; };

class B{
    public:
    static void test_amitie(const A& a){ std::cout << a.m_ << std::endl;};

};

int main(void){
    double x;
    A a;
    a.set(3) ;
    x = a.get();
    print(a);
    B::test_amitie(a);

}