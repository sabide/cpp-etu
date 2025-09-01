#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Entrez un entier : ";
    cin >> n;

    // Test parité
    if (n % 2 == 0)
        cout << n << " est pair." << endl;
    else
        cout << n << " est impair." << endl;

    // Test signe
    if (n > 0)
        cout << n << " est positif." << endl;
    else if (n < 0)
        cout << n << " est négatif." << endl;
    else
        cout << n << " est nul." << endl;

    return 0;
}
