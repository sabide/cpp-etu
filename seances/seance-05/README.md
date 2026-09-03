# Séance 5 — Composition et héritage

## Objectifs

Cette séance compare deux relations entre classes : la composition pour
exprimer « possède un » et l'héritage public pour exprimer « est utilisable
comme ». Elle introduit également la référence de base et le slicing.

## Conseils de travail

- Commencez par nommer la relation entre les objets avant de choisir la
  syntaxe.
- Vérifiez qu'une classe dérivée respecte le contrat de sa classe de base.
- Comparez attentivement `const Element& ref = triangle` et
  `Element copy = triangle` : la première ligne référence l'objet existant, la
  seconde construit un nouvel objet de base.
- Préférez la composition lorsqu'un objet contient simplement d'autres objets.
