#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Combien de notes ? (max 100) ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Nombre de notes invalide." << endl;
        return 1;
    }

    double notes[100];
    double somme = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "Note " << (i + 1) << " : ";
        cin >> notes[i];
        somme += notes[i];
    }

    double moyenne = somme / n;

    // Recherche min et max
    double min_note = notes[0];
    double max_note = notes[0];
    for (int i = 1; i < n; i++) {
        if (notes[i] < min_note) min_note = notes[i];
        if (notes[i] > max_note) max_note = notes[i];
    }

    cout << "Moyenne = " << moyenne << endl;
    cout << "Note minimale = " << min_note << endl;
    cout << "Note maximale = " << max_note << endl;

    return 0;
}
