#include <iostream>
using namespace std;

// Fonction factorielle
int factorielle(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    cout << "Entrez un entier n : ";
    cin >> n;

    cout << n << "! = " << factorielle(n) << endl;

    // pensez à faire des tests
    cout << "0! = " << factorielle(0) << " (attendu : 1)" << endl;
    cout << "1! = " << factorielle(1) << " (attendu : 1)" << endl;
    cout << "5! = " << factorielle(5) << " (attendu : 120)" << endl;

    return 0;
}
