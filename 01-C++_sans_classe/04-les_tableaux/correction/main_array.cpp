#include <iostream>
#include <cmath>
#include <array>
#include <algorithm>

using namespace std;

constexpr double PI = 3.141592653589793;
const int N = 100;

double f(double x) {
    return -sin(2.0 * PI * x) / (4.0 * PI * PI);
}

double fpp_exact(double x) {
    return sin(2.0 * PI * x);
}

int main() {
    constexpr double h = 1.0 / N;
    array<double, N+1> X{};
    array<double, N+1> F{};
    array<double, N+1> Fpp{};

    for (int i = 0; i <= N; i++) {
        X[i] = i * h;
        F[i] = f(X[i]);
    }

    for (int i = 1; i < N; i++) {
        Fpp[i] = (F[i+1] - 2*F[i] + F[i-1]) / (h*h);
    }

    double err_max = 0.0;
    for (int i = 1; i < N; i++) {
        err_max = max(err_max, fabs(Fpp[i] - fpp_exact(X[i])));
    }

    cout << "[std::array] Erreur max = " << err_max << endl;
    return 0;
}

