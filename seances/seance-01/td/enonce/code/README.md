# Code de départ — TD/TP 1

Chaque fichier correspond à un exercice du sujet. Les marqueurs `TODO`
indiquent le travail demandé. Le projet compile dès le départ, à l'exception
des diagnostics volontairement activés dans l'exercice 5.

```bash
make
./build/02-initialisation
./build/03-references
```

Pour reproduire les deux erreurs de l'exercice 5 :

```bash
make diagnostic-const-bind
make diagnostic-const-write
```

Ces deux dernières commandes doivent être refusées par le compilateur.
