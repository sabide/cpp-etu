# TD/TP 6 — Polymorphisme dynamique

Le programme initial compile et montre volontairement une différence entre
l'appel direct sur `Triangle` et l'appel à travers `const Element&`.

```sh
make
./td6
```

Au départ, la sortie contient notamment :

```text
appel direct : 2.5
via Element& : 0
```

Suivez les exercices du sujet dans l'ordre. Les commentaires `TODO` indiquent
les déclarations qui évolueront. Conservez les sanitizers pendant toute la
séance.
