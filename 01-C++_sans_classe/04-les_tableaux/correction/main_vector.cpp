#include <iostream>
#include <cmath>
#include <vector>
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

    vector<double> X(n+1), F(n+1), Fpp(n+1);

    for (int i = 0; i <= n; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }

    for (int i = 1; i < n; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    double err_max = 0.0;
    for (int i = 1; i < n; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }

    cout << "[std::vector] Erreur max = " << err_max << endl;
    return 0;
}

