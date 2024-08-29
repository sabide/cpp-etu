#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string& nom) : nom_(nom) {
        std::cout << "Animal " << nom_ << " créé.\n";
    }

    virtual ~Animal() {
        std::cout << "Animal " << nom_ << " détruit.\n";
    }

    virtual void parler() const = 0; // Méthode virtuelle pure

protected:
    std::string nom_;
};

// Interface Volant
class Volant {
public:
    virtual void voler() const = 0;
    virtual ~Volant() = default;
};

// Interface Nageant
class Nageant {
public:
    virtual void nager() const = 0;
    virtual ~Nageant() = default;
};

class Lion : public Animal {
public:
    Lion(const std::string& nom) : Animal(nom) {
        std::cout << "Lion " << nom_ << " créé.\n";
    }

    ~Lion() override {
        std::cout << "Lion " << nom_ << " détruit.\n";
    }

    void parler() const override {
        std::cout << nom_ << " dit : Roar!\n";
    }
};

class Oiseau : public Animal, public Volant {
public:
    Oiseau(const std::string& nom) : Animal(nom) {
        std::cout << "Oiseau " << nom_ << " créé.\n";
    }

    ~Oiseau() override {
        std::cout << "Oiseau " << nom_ << " détruit.\n";
    }

    void parler() const override {
        std::cout << nom_ << " dit : Tweet!\n";
    }

    void voler() const override {
        std::cout << nom_ << " vole dans le ciel!\n";
    }
};

class Canard : public Oiseau, public Nageant {
public:
    Canard(const std::string& nom) : Animal(nom), Oiseau(nom) {
        std::cout << "Canard " << nom_ << " créé.\n";
    }

    ~Canard() override {
        std::cout << "Canard " << nom_ << " détruit.\n";
    }

    void parler() const override {
        std::cout << nom_ << " dit : Coin coin!\n";
    }

    void nager() const override {
        std::cout << nom_ << " nage sur l'eau!\n";
    }
};

int main() {
    Animal* zoo[] = {
        new Lion("Simba"),
        new Oiseau("Tweety"),
        new Canard("Donald")
    };

    for (Animal* animal : zoo) {
        animal->parler();
        
        // Utilisation du dynamic_cast pour vérifier si l'animal peut voler ou nager
        if (Volant* volant = dynamic_cast<Volant*>(animal)) {
            volant->voler();
        }
        if (Nageant* nageant = dynamic_cast<Nageant*>(animal)) {
            nageant->nager();
        }
    }

    // Nettoyage de la mémoire
    for (Animal* animal : zoo) {
        delete animal;
    }

    return 0;
}