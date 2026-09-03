# Programme corrigé — TD/TP 3

Cette version finale relie directement les idées de la séance :

- la représentation de `IntArray` est privée ;
- le constructeur vérifie la capacité avant l'allocation ;
- le destructeur libère automatiquement le tableau ;
- les méthodes `const` observent l'objet sans modifier ses membres ;
- la copie et l'affectation sont provisoirement interdites.

```bash
make
make run
make diagnostics
```

La dernière commande vérifie que le compilateur refuse bien l'accès direct à
la représentation, la copie et l'affectation par copie.

L'invariant utilisé est :

- `size_ <= capacity_` ;
- si `capacity_ == 0`, alors `data_ == nullptr` ;
- si `capacity_ > 0`, `data_` désigne une zone de `capacity_` entiers.

Le constructeur public refuse ici `IntArray{0}`. Cela n'empêche pas l'état
interne `0 / 0 / nullptr` d'être cohérent ; il sera utile après déplacement en
séance 4.
