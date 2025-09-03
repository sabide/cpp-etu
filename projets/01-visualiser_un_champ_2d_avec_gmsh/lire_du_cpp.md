
# TD : Visualiser une fonction sur un maillage non structuré avec Gmsh (2h00)

## Contexte
L’objectif de ce TD est de découvrir la bibliothèque **Gmsh** utilisée en C++ pour générer et manipuler des maillages.  
Plutôt que de construire un maillage structuré "à la main", nous allons laisser Gmsh créer pour nous un maillage **non structuré** sur un domaine simple.  
Sur ce maillage, nous associerons ensuite à chaque nœud la valeur d’une fonction \( f(x,y) \), afin de produire un champ scalaire visualisable directement dans Gmsh.

## Objectif

À la fin de l’exercice, vous devrez être capable de générer un maillage d’un carré, d’évaluer une fonction scalaire sur les nœuds de ce maillage, et d’exporter le tout dans un fichier `.msh` pouvant être ouvert avec l’interface graphique de Gmsh.  
L’idée n’est pas seulement de programmer, mais surtout d’apprendre à lire et comprendre la documentation d’une bibliothèque C++ pour en tirer parti.  

## Indications

Vous allez utiliser plusieurs fonctions de l’API C++ de Gmsh. La documentation officielle donne pour chacune la signature exacte et le rôle précis. À vous de la consulter pour en comprendre le fonctionnement.  
Voici les principales fonctions dont vous aurez besoin :

- `gmsh::initialize()` pour initialiser Gmsh au début du programme ;  
- `gmsh::model::occ::addRectangle(...)` pour créer un domaine carré ;  
- `gmsh::model::occ::synchronize()` pour synchroniser la géométrie avec le modèle ;  
- `gmsh::model::mesh::generate(...)` pour construire un maillage non structuré en 2D ;  
- `gmsh::model::mesh::getNodes(...)` pour récupérer la liste des nœuds et leurs coordonnées ;  
- `gmsh::view::add(...)` et `gmsh::view::addModelData(...)` pour associer à chaque nœud une valeur scalaire ;  
- `gmsh::write(...)` pour exporter le résultat dans un fichier au format `.msh` ;  
- `gmsh::fltk::run()` pour lancer la visualisation interactive ;  
- `gmsh::finalize()` pour terminer proprement le programme.

## Travail demandé

Vous devez écrire un programme C++ qui réalise les étapes suivantes :  
1. Initialiser Gmsh et créer une géométrie correspondant au carré \([0,1] \times [0,1]\).  
2. Générer un maillage 2D non structuré de ce domaine.  
3. Récupérer les coordonnées des nœuds du maillage.  
4. Évaluer en chaque nœud la fonction \( f(x,y) = \sin(\pi x)\cos(\pi y) \).  
5. Créer une "view" dans Gmsh et associer à chaque nœud la valeur calculée.  
6. Sauvegarder le fichier `.msh` puis le visualiser avec l’interface graphique.

## Compilation
```sh
g++ main.cpp -o main.x -lgmsh
```
## Résultat attendu

À l’issue du TD, vous devez obtenir un fichier de maillage enrichi par un champ scalaire.  
Lorsque vous ouvrez ce fichier dans Gmsh, vous devez voir apparaître le carré maillé en triangles, coloré en fonction de la valeur de \( f(x,y) \).  
La couleur doit refléter les variations de la fonction, avec par exemple des zones positives et négatives selon la position des nœuds.

## Pour aller plus loin

Vous pouvez modifier la taille caractéristique utilisée lors de la génération du maillage pour raffiner la discrétisation et mieux représenter la fonction.  
Vous pouvez également essayer d’autres fonctions, par exemple une parabole \( f(x,y) = x^2 + y^2 \) ou une gaussienne centrée en \((0.5,0.5)\).  
Enfin, vous pouvez remplacer le carré par un disque ou un autre domaine plus complexe afin de constater la flexibilité des outils proposés par Gmsh.
