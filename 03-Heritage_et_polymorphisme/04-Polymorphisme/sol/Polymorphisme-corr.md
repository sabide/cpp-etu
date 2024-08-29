# Elements de correction 

Cette solution implémente les classes `Element`, `Triangle`, et `Quadrangle`, ainsi qu'un programme principal démontrant le calcul des aires pour différentes figures géométriques.

## Explications de la Solution :

1. **Classe `Element`** :
   - C'est une classe abstraite qui définit une interface commune pour toutes les figures géométriques via la méthode virtuelle pure `Aire()`.

2. **Classe `Triangle`** :
   - Représente un triangle avec trois sommets définis par leurs coordonnées.
   - La méthode `Aire()` implémente la formule standard pour l'aire d'un triangle en utilisant les coordonnées de ses sommets.

3. **Classe `Quadrangle`** :
   - Représente un quadrilatère avec quatre sommets.
   - L'aire est calculée en divisant le quadrilatère en deux triangles et en additionnant leurs aires.

4. **Programme principal `main`** :
   - Les objets `Triangle` et `Quadrangle` sont créés dynamiquement et stockés dans un tableau de pointeurs `Element`.
   - Le polymorphisme est démontré en appelant `Aire()` sur des objets de type `Element*`, ce qui invoque la méthode appropriée en fonction du type réel de l'objet (triangle ou quadrilatère).
   - Enfin, la mémoire allouée dynamiquement est libérée.


## Commentaires du code source

- **Création des Objets** : Les objets `Triangle` et `Quadrangle` sont créés avec des coordonnées spécifiques pour les sommets.
- **Utilisation du Polymorphisme** : Le polymorphisme est utilisé pour appeler la méthode `Aire()` sur des objets de type `Element*`. Cela permet d'invoquer la méthode appropriée en fonction du type concret de l'objet (triangle ou quadrilatère).
- **Destruction des Objets** : La mémoire allouée dynamiquement est correctement libérée grâce à l'utilisation d'un destructeur virtuel.