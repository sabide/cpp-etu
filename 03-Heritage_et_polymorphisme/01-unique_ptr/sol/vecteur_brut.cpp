#include <iostream>



Box box;

class Vecteur {
public:
    Vecteur(size_t taille)
        : taille_(taille), data_(new double[taille]) {}

    ~Vecteur() {
        delete[] data_; // Libération manuelle de la mémoire allouée
    }

    double* getData() const {
        return data_;
    }

    size_t getTaille() const {
        return taille_;
    }

    double calculerMoyenne() const {
        double somme = 0.0;
        for (size_t i = 0; i < taille_; ++i) {
            somme += data_[i];
        }
        return somme / taille_;
    }

private:
    size_t taille_;
    double* data_;  // Pointeur brut pour gérer le tableau de doubles
};

int main() {
    size_t taille = 5;

    // Création d'un vecteur de taille 5
    Vecteur vecteur(taille);

    // Remplissage du vecteur
    double* data = vecteur.getData();
    data[0] = 1.2;
    data[1] = 2.3;
    data[2] = 3.4;
    data[3] = 4.5;
    data[4] = 5.6;

    // Calcul de la moyenne
    double moyenne = vecteur.calculerMoyenne();

    // Affichage du résultat
    std::cout << "La moyenne des éléments du vecteur est " << moyenne << std::endl;

    return 0;
}

