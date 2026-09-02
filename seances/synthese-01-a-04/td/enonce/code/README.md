# TD/TP de synthèse — Gmsh

Le projet initial produit immédiatement `mesh.msh`. Le TD fait ensuite évoluer
`MeshConfig`, introduit `GmshSession`, puis génère `coarse.msh` et `fine.msh`.

```bash
make
./mesh_demo
gmsh mesh.msh
```

Après chaque modification, relancer `make`. La fonction
`generate_rectangle` contient les appels techniques à Gmsh et n'est pas à
réécrire.
