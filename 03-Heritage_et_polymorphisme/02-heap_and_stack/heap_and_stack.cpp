#include <iostream>
#include <chrono>

int main() {
    const int size = 2000000;
    
    // Allouer le tableau sur la pile
    double stackArray[size];

    // Allouer le tableau sur le tas
    double * heapArray = new double[size];
    
    // Remplir et mesurer le temps pour le tableau sur la pile
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        stackArray[i] = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Temps pour remplir le tableau sur la pile: " << duration.count() << " secondes" << std::endl;

    // Remplir et mesurer le temps pour le tableau sur le tas
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        heapArray[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Temps pour remplir le tableau sur le tas: " << duration.count() << " secondes" << std::endl;

    // Mesurer le temps d'accès aux éléments sur la pile
    int sum = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        sum += stackArray[i];
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Temps pour accéder aux éléments du tableau sur la pile: " << duration.count() << " secondes" << std::endl;

    // Mesurer le temps d'accès aux éléments sur le tas
    sum = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        sum += heapArray[i];
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Temps pour accéder aux éléments du tableau sur le tas: " << duration.count() << " secondes" << std::endl;

    // Libérer la mémoire allouée sur le tas
    delete[] heapArray;

    return 0;
}