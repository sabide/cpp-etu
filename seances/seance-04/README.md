# Séance 4 — Copie, déplacement et opérateurs

## Objectifs

Cette séance donne à `IntArray` un comportement proche d'un type natif : une
copie indépendante, un transfert de ressource par déplacement et une interface
naturelle.

## Conseils de travail

- Dessinez les objets, leurs pointeurs et les allocations avant d'écrire le
  code.
- Distinguez toujours la création d'un objet de l'affectation d'un objet qui
  possède déjà une ressource.
- Après un déplacement, vérifiez à la fois la destination et l'état valide de la
  source.
- Retenez que `std::move` permet de sélectionner une opération de déplacement ;
  il ne transfère pas lui-même la ressource.
- La règle de cinq sert à comprendre la gestion directe ; dans le code courant,
  recherchez plutôt la règle de zéro.
