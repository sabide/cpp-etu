### Exercice : Gestion de la Mémoire Dynamique en C++ avec et sans `std::unique_ptr`

#### Contexte

Vous êtes en train de développer une application qui manipule des vecteurs de nombres flottants (`double`). Vous devez implémenter une classe `Vecteur` qui gère dynamiquement un tableau de `double`. Cette classe doit également fournir une méthode pour calculer la moyenne des éléments du tableau.

#### Objectifs de l'exercice

1. **Comprendre l'importance de la gestion de la mémoire en C++.**
2. **Apprendre à utiliser les pointeurs bruts pour la gestion manuelle de la mémoire.**
3. **Découvrir l'utilisation de `std::unique_ptr` pour simplifier et sécuriser la gestion de la mémoire.**

#### Étape 1 : Implémentation avec des Pointeurs Bruts

1. Créez une classe `Vecteur` qui contient :
   - Un membre `double* data_` pour stocker un tableau dynamique de `double`.
   - Un membre `size_t taille_` pour stocker la taille du tableau.
   - Un constructeur qui alloue dynamiquement un tableau de `double` de la taille donnée.
   - Un destructeur qui libère la mémoire allouée.
   - Une méthode `double calculerMoyenne() const` qui retourne la moyenne des éléments du tableau.

2. Dans le `main()`, créez une instance de `Vecteur`, remplissez le tableau avec quelques valeurs, et affichez la moyenne.

#### Étape 2 : Implémentation avec `std::unique_ptr`

1. Modifiez la classe `Vecteur` pour utiliser un `std::unique_ptr<double[]>` à la place de `double*` pour gérer le tableau dynamique.

2. Supprimez le destructeur explicite, car `std::unique_ptr` gère automatiquement la libération de la mémoire.

3. Répétez les étapes du `main()` pour remplir le tableau et afficher la moyenne.

#### Questions

1. **Quel est le principal risque lorsqu'on utilise des pointeurs bruts pour gérer la mémoire ?**
2. **Pourquoi `std::unique_ptr` est-il plus sûr que l'utilisation de pointeurs bruts ?**
3. **Que se passe-t-il si vous oubliez de libérer la mémoire allouée dynamiquement avec `new` dans le destructeur ?**

#### Conclusion

Une fois les deux implémentations réalisées, comparez-les. Notez la simplicité et la sécurité apportées par `std::unique_ptr` par rapport à la gestion manuelle de la mémoire avec des pointeurs bruts. Cela vous aidera à comprendre l'importance de l'utilisation des pointeurs intelligents en C++ pour éviter les fuites de mémoire et les erreurs de gestion de la mémoire.

---

**Note** : Le passage de pointeurs bruts à `std::unique_ptr` permet d'améliorer la robustesse de votre code en simplifiant la gestion de la mémoire et en réduisant les risques d'erreurs courantes, telles que les fuites de mémoire.