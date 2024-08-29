#include <iostream>
#include <vector>

class Monome {
private:
    double coeff_;
    int degre_ ;
public:
    friend class poly; // poly peut modifier Monome
// ...
};


class poly{
private:
    std::vector<double> monomes;
public:
    poly(int n){  
        monomes.reserve(n);
    } ;
    poly(std::vector<double>& coeffs){ 
        monomes=coeffs;
    } ;

    friend void dbg(const std::string& , const poly& );    
    void change_coeff(Monome& m );

    friend std::ostream& operator << (std::ostream& stream, const poly& P){
        for(auto i=0; i <  P.monomes.size() ; ++i)
            stream  <<  P.monomes[i] << " " ;
        return stream ;
    };
    
};

void dbg(const std::string& nom, const poly& P){
    std::cout << nom << " " ;
    for(auto i=0; i <  P.monomes.size() ; ++i){
        std::cout  <<  P.monomes[i] << " " ;
    }

};

void poly::change_coeff(Monome& m ){
    m.coeff_ = this->monomes[m.degre_] ;
};

int main(void){
    poly P(10);
    
    std::vector<double>  w {1,2,3,3,1} ; 
    poly Q( w );
//    dbg("toto",Q);
    std::cout << Q << std::endl;

    return 0;
}
