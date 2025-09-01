#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

constexpr double PI = 3.141592653589793;

double f(double x) {
    return -sin(2.0 * PI * x) / (4.0 * PI * PI);
}

double fpp_exact(double x) {
    return sin(2.0 * PI * x);
}

int main() {
    int n = 100;
    double h = 1.0 / n;

    double* X = new double[n+1];
    double* F = new double[n+1];
    double* Fpp = new double[n+1];

    // initialisation
    for (int i = 0; i <= n; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }

    // différences finies
    for (int i = 1; i < n; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    // erreur max
    double err_max = 0.0;
    for (int i = 1; i < n; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }

    cout << "[Pointeurs] Erreur max = " << err_max << endl;

    delete[] X;
    delete[] F;
    delete[] Fpp;
    return 0;
}

