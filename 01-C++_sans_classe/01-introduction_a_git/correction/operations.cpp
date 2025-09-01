#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Entrez deux entiers : ";
    cin >> a >> b;

    cout << "Somme       : " << a + b << endl;
    cout << "Différence  : " << a - b << endl;
    cout << "Produit     : " << a * b << endl;

    if (b != 0) {
        cout << "Quotient    : " << a / b << endl;
        cout << "Reste       : " << a % b << endl;
    } else {
        cout << "Division impossible (b = 0)" << endl;
    }

    return 0;
}
