#include <iostream>
#include <vector>
#include <cmath>
#include <fftw3.h>

// Différence max pour des vecteurs de double
double max_abs_diff_double(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) return INFINITY;
    double emax = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        double e = std::fabs(a[i] - b[i]);
        if (e > emax) emax = e;
    }
    return emax;
}

// ----------------------------
// FFT 1D (réel -> complexe -> réel)
// ----------------------------
void demo_fft_1d(size_t N) {
    std::cout << "\n=== FFT 1D (R2C/C2R) N=" << N << " ===\n";

    // Allocation
    double* in  = (double*) fftw_malloc(sizeof(double) * N);
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * (N/2 + 1));

    // Signal test: somme de sinus/cosinus
    std::vector<double> ref(N);
    for (size_t i = 0; i < N; ++i) {
        double x = double(i) / double(N);
        ref[i] = std::sin(2.0 * M_PI * 5.0 * x) + 0.5 * std::cos(2.0 * M_PI * 12.0 * x);
        in[i] = ref[i];
    }

    // Plans
    fftw_plan plan_fwd = fftw_plan_dft_r2c_1d((int)N, in, out, FFTW_ESTIMATE);
    fftw_plan plan_bwd = fftw_plan_dft_c2r_1d((int)N, out, in, FFTW_ESTIMATE);

    // Aller
    fftw_execute(plan_fwd);

    // Retour
    fftw_execute(plan_bwd);

    // Normalisation (FFTW ne normalise pas)
    std::vector<double> rec(N);
    for (size_t i = 0; i < N; ++i) rec[i] = in[i] / double(N);

    // Erreur
    double err = max_abs_diff_double(ref, rec);
    std::cout << "Erreur max reconstruction (1D) = " << err << "\n";

    // Nettoyage
    fftw_destroy_plan(plan_fwd);
    fftw_destroy_plan(plan_bwd);
    fftw_free(in);
    fftw_free(out);
}

// ----------------------------
// FFT 2D (réel -> complexe -> réel)
// Dimensions: Nx x Ny
// Sortie complexe de taille Nx x (Ny/2+1)
// ----------------------------
void demo_fft_2d(size_t Nx, size_t Ny) {
    std::cout << "\n=== FFT 2D (R2C/C2R) Nx=" << Nx << " Ny=" << Ny << " ===\n";

    // Allocation
    double* in = (double*) fftw_malloc(sizeof(double) * Nx * Ny);
    fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * Nx * (Ny/2 + 1));

    // Champ test: motif périodique lisse
    std::vector<double> ref(Nx * Ny);
    for (size_t ix = 0; ix < Nx; ++ix) {
        double x = double(ix) / double(Nx);
        for (size_t iy = 0; iy < Ny; ++iy) {
            double y = double(iy) / double(Ny);
            double val = std::sin(2.0 * M_PI * 3.0 * x) * std::cos(2.0 * M_PI * 4.0 * y)
                       + 0.3 * std::cos(2.0 * M_PI * 2.0 * x + 2.0 * M_PI * 1.0 * y);
            ref[ix * Ny + iy] = val;
            in[ix * Ny + iy] = val;
        }
    }

    // Plans 2D
    fftw_plan plan_fwd = fftw_plan_dft_r2c_2d((int)Nx, (int)Ny, in, out, FFTW_ESTIMATE);
    fftw_plan plan_bwd = fftw_plan_dft_c2r_2d((int)Nx, (int)Ny, out, in, FFTW_ESTIMATE);

    // Aller
    fftw_execute(plan_fwd);

    // Retour
    fftw_execute(plan_bwd);

    // Normalisation (par Nx*Ny)
    std::vector<double> rec(Nx * Ny);
    double norm = double(Nx) * double(Ny);
    for (size_t i = 0; i < Nx * Ny; ++i) rec[i] = in[i] / norm;

    // Erreur
    double err = max_abs_diff_double(ref, rec);
    std::cout << "Erreur max reconstruction (2D) = " << err << "\n";

    // Nettoyage
    fftw_destroy_plan(plan_fwd);
    fftw_destroy_plan(plan_bwd);
    fftw_free(in);
    fftw_free(out);
}

int main() {
    // Démo 1D
    demo_fft_1d(1024);

    // Démo 2D
    demo_fft_2d(128, 96);

    return 0;
}
