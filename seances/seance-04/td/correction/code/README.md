# TD/TP 4 — code de correction

Cette référence couvre le parcours obligatoire : copie indépendante,
affectation par copie, constructeur et affectation de déplacement, réutilisation
de la source déplacée et `operator[]` const/non const.

```bash
make
make run
```

La classe conserve l'état interne vide `0 / 0 / nullptr` comme état valide,
tout en refusant `IntArray{0}` dans son constructeur public.
