
# Exercices C++ – Partie impérative (sans objets)

Ces cinq exercices permettent de balayer les notions fondamentales de la programmation en C++ impératif :

* **Entrées / sorties (`cin`, `cout`)** : apprendre à communiquer avec l’utilisateur est la première étape d’un programme interactif. L’étudiant s’entraîne à lire des données saisies au clavier et à afficher des résultats à l’écran, en se familiarisant avec la bibliothèque standard `<iostream>`.

* **Variables et opérateurs** : manipuler des valeurs numériques nécessite de savoir déclarer des variables, leur donner un type (`int`, `float`, `double`), puis utiliser les opérateurs arithmétiques et logiques. C’est le socle de tout calcul automatisé.

* **Conditions** : la structure `if / else` permet de prendre des décisions en fonction des données. Cela introduit la logique de branchement, indispensable pour rendre un programme adaptatif (tester la parité d’un nombre, comparer des valeurs, etc.).

* **Boucles** : `for` et `while` sont des outils essentiels pour répéter des instructions. Grâce à elles, l’étudiant apprend à itérer sur une séquence de valeurs, ce qui ouvre la voie à des algorithmes plus complexes (par ex. calcul de la factorielle).

* **Fonctions** : définir une fonction, c’est isoler un traitement dans un bloc réutilisable. Cela favorise la lisibilité, la modularité et la réutilisation du code. L’étudiant découvre ainsi comment structurer un programme en sous-programmes cohérents.

* **Tableaux simples** : manipuler plusieurs données de même type nécessite une structure de stockage. Les tableaux permettent de parcourir une collection de valeurs, d’effectuer des calculs (moyenne, min, max), et constituent une première approche des structures de données.


## Exercice 1 — Hello World amélioré

Écrire un programme `hello.cpp` qui :

1. Affiche le message `Hello World!`
2. Demande à l’utilisateur son **prénom** et affiche :

   ```
   Bonjour Alice !
   ```

---

## Exercice 2 — Calculs et variables

Écrire un programme `operations.cpp` qui :

1. Lit deux entiers `a` et `b`,
2. Affiche la somme, la différence, le produit, et le quotient entier (division euclidienne) de `a` et `b`.

---

## Exercice 3 — Contrôle de flux (conditions)

Écrire un programme `pair.cpp` qui :

1. Lit un entier `n`,
2. Indique s’il est pair ou impair,
3. Indique s’il est positif, négatif ou nul.

---

## Exercice 4 — Boucles et fonctions

Écrire un programme `factorielle.cpp` qui :

1. Lit un entier `n`,
2. Calcule sa factorielle :

   $$
   n! = 1 \times 2 \times \dots \times n
   $$

   en utilisant une boucle `for`,
3. Implémente aussi une fonction `int factorielle(int n)` qui effectue le calcul,
4. Vérifie le résultat avec quelques tests (`n=0`, `n=1`, `n=5`).

---

## Exercice 5 — Tableaux et algorithme simple

Écrire un programme `moyenne.cpp` qui :

1. Demande à l’utilisateur combien de notes il souhaite entrer (max 100),
2. Stocke les notes dans un tableau,
3. Calcule et affiche la moyenne des notes,
4. Affiche la plus grande et la plus petite note.

---
