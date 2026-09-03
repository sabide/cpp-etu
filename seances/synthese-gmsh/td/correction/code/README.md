# Correction du TD/TP de synthèse — Gmsh

```bash
make
./mesh_demo
gmsh coarse.msh
gmsh fine.msh
```

Le programme doit créer deux maillages du même rectangle. `fine.msh` utilise
une taille de maille plus petite que `coarse.msh`.
