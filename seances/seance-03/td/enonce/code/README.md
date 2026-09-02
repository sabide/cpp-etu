# Code de départ — TD/TP 3

Ce projet reprend la `struct IntArray` obtenue à la fin de la séance 2. Il
compile dès le départ, mais sa représentation est publique et l'appelant doit
encore appeler `initialize()` puis `destroy()`.

```bash
make
make run
```

Conservez les sanitizers actifs pendant tout le TD. Les marqueurs `TODO` de
`int_array.hpp` résument la transformation attendue :

1. formuler et protéger l'invariant ;
2. passer de `struct` à `class` avec une représentation privée ;
3. construire uniquement des objets utilisables ;
4. lier la mémoire à la durée de vie de l'objet avec le destructeur ;
5. constater que la copie automatique est incorrecte, puis l'interdire.

Le TD3 ne demande pas encore d'implémenter une copie indépendante : ce sera le
point de départ de la séance 4.
