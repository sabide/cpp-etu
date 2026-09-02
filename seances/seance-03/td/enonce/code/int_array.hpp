#pragma once

#include <cstddef>

// Point de départ : la représentation est encore publique et l'appelant doit
// gérer explicitement l'initialisation et la libération de la mémoire.
struct IntArray {
    std::size_t capacity{};
    std::size_t size{};
    int* data{nullptr};

    void initialize(std::size_t initial_capacity);
    void destroy();

    void push_back(int value);
    int at(std::size_t index) const;
    int sum() const;
    void fill(int value);
};

// TODO pendant le TD :
// 1. remplacer struct par class et rendre la représentation privée ;
// 2. remplacer initialize/destroy par des constructeurs et un destructeur ;
// 3. ajouter size() et capacity() ;
// 4. interdire provisoirement la copie avec = delete.
