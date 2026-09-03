# Séance 6 — Interfaces abstraites et polymorphisme dynamique

## Objectifs

Cette séance montre comment un même algorithme peut choisir un comportement
selon le type réel de l'objet. Le fil rouge utilise une interface commune pour
intégrer plusieurs fonctions mathématiques avec la même quadrature.

## Conseils de travail

- Identifiez d'abord l'opération minimale dont l'algorithme a besoin.
- Passez les objets polymorphes par référence ou par pointeur afin de conserver
  leur type réel.
- Ajoutez systématiquement `override` aux redéfinitions attendues et laissez le
  compilateur contrôler la signature.
- Une classe de base utilisée pour le polymorphisme doit posséder un destructeur
  virtuel.
