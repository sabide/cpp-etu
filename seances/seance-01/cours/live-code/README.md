# Exemples du cours — séance 1

Ces programmes permettent de reprendre les démonstrations vues en cours. Les
fichiers sont numérotés dans l'ordre de la séance.

Pour chaque exemple, lisez le code, prévoyez le résultat ou le diagnostic, puis
compilez avant de comparer avec votre réponse.

```bash
make
make run
```

## Slide 2 — Même syntaxe, langages différents

Fichiers : `c_vs_cpp.c` et `c_vs_cpp.cpp`.

La commande suivante compile d'abord le programme en C, puis tente de compiler
le même code en C++ :

```bash
make slide-02
```

La compilation C réussit. La compilation C++ est refusée parce que `malloc`
renvoie un `void*`, qui n'est pas converti implicitement en `int*` en C++.

## 01 — Initialisation avec accolades

Fichier : `01-initialisation-accolades.cpp`.

Observez les initialisations acceptées, puis lancez :

```bash
make error-narrowing
```

Le compilateur refuse `int invalid{3.9};` car les accolades rendent visible la
perte d'information.

## 02 — `const` fait vérifier l'intention

Fichier : `02-const-fait-verifier.cpp`.

Prévoyez le diagnostic produit par une affectation à `reference_temperature`,
puis utilisez `make error-const`. `const` permet au compilateur de vérifier
qu'une valeur annoncée comme constante ne change pas.

## 03 — Pointeur ou référence

Fichier : `03-pointeur-ou-reference.cpp`.

Comparez `add_one_pointer(&first)` et `add_one_reference(second)`. Seul le
pointeur permet de représenter l'absence d'objet avec `nullptr`.

## 04 — Une référence est un alias

Fichier : `04-reference-alias.cpp`.

Prévoyez la valeur de `z` après `alias = 8`, puis après `toto(z) = 18`. Les
adresses affichées montrent que les références donnent un autre accès au même
objet. Ne renvoyez jamais une référence vers une variable locale qui disparaît
à la fin de l'appel.

## 05 — `T`, `T&` et `const T&`

Fichier : `05-signatures-expriment-intention.cpp`.

Classez `translated`, `translate` et `norm` avant l'exécution : `T` reçoit sa
propre valeur, `T&` modifie l'objet fourni et `const T&` l'observe sans le
modifier par cette référence.

## 06 — Lire un diagnostic

Fichier : `06-diagnostic-signature.cpp`.

Exécutez la version correcte, puis `make error-signature`. Recherchez dans le
diagnostic pourquoi un objet `const` ne peut pas être donné à une fonction qui
attend `Point&`.

## 07 — Retour à `IntArray`

Fichier : `07-int-array-signatures.cpp`.

Lisez d'abord les signatures : `create_array(IntArray&)` et
`push_back(IntArray&)` modifient l'objet fourni, tandis que
`at(const IntArray&)` l'observe. L'appel final à `destroy_array(values)` rappelle
que la mémoire reste encore gérée manuellement.
