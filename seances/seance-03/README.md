# Séance 3 — Classes, invariants et RAII

## Objectifs

Cette séance transforme `IntArray` en objet responsable de son état et de sa
ressource. Elle introduit la représentation privée, l'invariant, le constructeur,
le destructeur et le RAII.

## Conseils de travail

- Formulez l'invariant avant d'écrire l'interface de la classe.
- Vérifiez les conditions de construction avant d'allouer la ressource.
- Utilisez les méthodes publiques au lieu de contourner la représentation
  privée.
- Suivez la durée de vie de l'objet pour comprendre quand la ressource est
  acquise puis libérée.
- La copie reste provisoirement interdite : elle sera construite à la séance 4.

## Fichiers

- `cours/` : support de cours ;
- `td/enonce/` : sujet du TD/TP et projet `IntArray` de départ.
