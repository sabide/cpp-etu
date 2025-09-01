# Mise en pratique des tableaux 
Temps estimé : **1 heure**.

## Objectif
Les tableaux constituent une structure fondamentale en programmation et jouent un rôle central dans de nombreux algorithmes en analyse numérique.  
En C++, plusieurs manières existent pour les manipuler : à l’aide de pointeurs bruts, de `std::array` ou encore de `std::vector`.  

L’objectif de ce TD est de comparer ces différentes approches à travers un exemple simple mais représentatif : l’approximation numérique d’une dérivée seconde.


## La méthode des différences finies
Nous cherchons à approximer la dérivée seconde d’une fonction $f$ à partir de ses valeurs discrètes.  
On considère une grille uniforme de points  
$$
x_i = i h, \quad 0 \leq i \leq n, \quad h = \tfrac{1}{n}.
$$  

Pour une fonction $f$, on note $f_i = f(x_i)$. La dérivée seconde en un point intérieur peut alors être approchée par la formule classique des différences finies centrées :
$$
f''(x_i) \approx \frac{f_{i+1} - 2 f_i + f_{i-1}}{h^2}, \quad 0 < i < n.
$$

Dans ce TD, nous implémenterons cette formule en C++ selon trois approches différentes de gestion de tableaux.

## Déroulement du travail

### 1. Écriture de l’algorithme
Avant toute implémentation, on prend le temps de rédiger l’algorithme sur papier.  
Les étapes à prévoir sont :
1. Initialiser les tableaux représentant la grille $X$, les valeurs de la fonction $F$, et l’approximation de la dérivée seconde $F''$.  
2. Mettre en œuvre la formule des différences finies.  
3. Comparer le résultat à la dérivée seconde exacte, et calculer l’erreur maximale commise.  

Cette étape préparatoire permet de bien comprendre la structure générale du code.

### 2. Implémentation avec pointeurs 
On commence par la version la plus basique, avec une gestion manuelle de la mémoire.  
Dans `main.cpp`, on déclare trois tableaux dynamiques :
- $X$, qui contient les coordonnées de la grille : $x_i = i \times h$,
- $F$, qui contient les valeurs $f_i = -\frac{\sin(2\pi x_i)}{4\pi^2}$,
- $F''$, qui contient l’approximation de la dérivée seconde à l’aide de la formule précédente.  

Une fois la méthode validée, il s’agira d’ajouter une fonction qui calcule l’erreur maximale entre l’approximation et la dérivée seconde exacte.  
Enfin, on refactorise le code : chaque grande étape (initialisation, calcul de $F''$, calcul de l’erreur) doit idéalement devenir une fonction séparée.


### 3. Implémentation avec `std::array`
Dans un second temps, on reprend le code précédent mais en remplaçant les pointeurs par des `std::array`.  
L’intérêt est de constater que l’interface change peu, mais que la sécurité est renforcée : `std::array` gère la taille de manière statique et limite les erreurs liées à la manipulation des pointeurs.  

On prendra le temps de comparer cette approche à la précédente :  
- meilleure lisibilité,  
- moins d’erreurs de segmentation,  
- mais moins flexible en cas de tailles non connues à la compilation.


### 4. Implémentation avec `std::vector`
Enfin, on réalise une troisième version avec `std::vector`.  
Contrairement à `std::array`, le `std::vector` gère dynamiquement la taille et permet une grande flexibilité. C’est l’approche la plus couramment utilisée en C++ moderne pour manipuler des tableaux lorsque la taille n’est pas fixée à la compilation.  

On discutera de ses avantages (gestion dynamique, sécurité mémoire, fonctions utilitaires) et de ses inconvénients (léger surcoût en performance par rapport aux pointeurs bruts).


## Questions de synthèse
Pour conclure, prenez un moment pour réfléchir et répondre aux questions suivantes :  

1. Quelles différences essentielles observez-vous entre les pointeurs, les `std::array` et les `std::vector`, en particulier en termes de gestion mémoire et de sécurité ?  
2. En quoi la modularité et la lisibilité du code sont-elles améliorées lorsqu’on introduit des fonctions et qu’on utilise des conteneurs sûrs comme `std::array` ou `std::vector` ?  
3. Si vous deviez choisir une seule approche pour vos futurs calculs numériques en C++, laquelle retiendriez-vous et pourquoi ?  

