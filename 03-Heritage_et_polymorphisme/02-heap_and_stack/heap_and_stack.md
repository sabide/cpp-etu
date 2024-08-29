### Sujet : Comparaison des performances entre pile et tas en mémoire

#### Objectif :
- Comparer le temps d'allocation et d'accès en mémoire entre la pile et le tas.

#### Consignes :
1. Créez un tableau de 1 000 000 d'entiers (ou plus) alloué sur la pile.
2. Créez un tableau de 1 000 000 d'entiers (ou plus) alloué sur le tas à l'aide de `new`.
3. Remplissez chaque tableau avec des valeurs aléatoires ou séquentielles.
4. Mesurez et affichez le temps nécessaire pour remplir chaque tableau.
5. Mesurez et affichez le temps nécessaire pour accéder à chaque élément des deux tableaux.

#### Code exemple :

```cpp
#include <iostream>
#include <chrono>

int main() {
    const int size = 1000000;
    
    // Allouer le tableau sur la pile
    int stackArray[size];
    
    // Allouer le tableau sur le tas
    int* heapArray = new int[size];
    
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
```

#### Questions de réflexion :
1. Quel est l'impact de la taille du tableau sur les performances de la pile et du tas ?
2. Pourquoi l'allocation sur le tas est-elle généralement plus lente que sur la pile ?
3. Comment le cache mémoire influence-t-il les temps d'accès aux éléments des tableaux ?

---

### Correction

#### Explications :

1. **Temps d'allocation :**
   - L'allocation sur la pile est très rapide car elle se fait en modifiant simplement un pointeur de pile, sans faire appel au système d'exploitation.
   - L'allocation sur le tas, en revanche, implique un appel au système d'exploitation pour obtenir un segment de mémoire, ce qui est plus coûteux en temps.

2. **Temps d'accès :**
   - L'accès aux éléments sur la pile est souvent plus rapide car ces données sont généralement mieux organisées en mémoire, réduisant ainsi les cache-miss.
   - L'accès aux éléments sur le tas peut être plus lent car les données peuvent être dispersées en mémoire, augmentant le risque de cache-miss.

3. **Impact de la taille du tableau :**
   - Sur la pile, la taille du tableau est limitée par la taille de la pile allouée au programme, ce qui peut entraîner des débordements si le tableau est trop grand.
   - Sur le tas, la taille est limitée uniquement par la mémoire disponible sur le système, offrant plus de flexibilité mais au prix de performances.

#### Conclusion :

- **Pile :** rapide pour les petites allocations, avec un accès efficace aux données, mais limitée en taille.
- **Tas :** offre une grande flexibilité en termes de taille et de durée de vie des données, mais avec un coût de performance plus élevé en termes d'allocation et d'accès.