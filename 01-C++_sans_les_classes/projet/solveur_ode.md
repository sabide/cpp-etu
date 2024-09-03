# Résolution des équations de Lotka-Volterra en C++

Les équations de Lotka-Volterra modélisent la dynamique de population dans un système écologique où deux espèces interagissent. 
Les équations décrivent comment les populations de proies et de prédateurs évoluent au fil du temps en fonction de leurs taux de croissance et de leurs interactions.
Le système d'équations différentielles ordinaires (EDO) est donné par :
$$
\frac{dx}{dt} = \alpha x - \beta x y
$$

$$
\frac{dy}{dt} = \delta x y - \gamma y
$$

où :
- $ x(t) $ représente la population de proies à un instant $t$.
- $ y(t) $ représente la population de prédateurs à un instant $t$.
- $ \alpha, \beta, \gamma, \delta $ sont des paramètres positifs du modèle.

on se propose de résoudre le système d'équations de Lotka-Volterra en utilisant deux méthodes numériques : la méthode d'Euler explicite et la méthode d'Euler implicite. Vous allez écrire un programme en C++ sans utiliser de classes, pour calculer et afficher l'évolution des populations de proies et de prédateurs sur une période donnée. Dans un premier temps on vous donne les paramètres du modéle  Lotka-Volterra. On choisit les paramètres suivants :
     - $ \alpha = 1.0$
     - $ \beta = 0.1 $
     - $ \gamma = 1.5 $
     - $ \delta = 0.075 $
Pour la condition initiale les populations des proies et des prédateurs sont :
     - $ x_0 = 10.0 $
     - $ y_0 = 5.0 $

## Méthode d'Euler explicite
   - Implémentez une fonction `euler_explicit` qui résout le système d'équations en utilisant la méthode d'Euler explicite.
   - La fonction doit prendre en entrée le pas de temps `h`, le nombre de pas `n_steps`, ainsi que les valeurs initiales `x0` et `y0`.
   - La fonction doit afficher l'évolution des populations à chaque étape.
   - Sauvegardez les résultats dans un fichier selon le format : `temps`, `x`, `y`.

## Méthode d'Euler implicite
   - Implémentez une fonction `euler_implicit` qui résout le système d'équations en utilisant la méthode d'Euler implicite.
   - Cette méthode peut nécessiter une itération pour résoudre les équations implicites à chaque pas de temps. Utilisez une méthode simple comme celle des points fixes pour cette itération.
   - La fonction doit prendre en entrée les mêmes paramètres que `euler_explicit` et afficher l'évolution des populations.
   - Sauvegardez les résultats dans un fichier selon le format : `temps`, `x`, `y`.

## Comparaison des résultats (rappels de méthodes-numériques)
   - Exécutez votre programme avec un pas de temps $h = 0.01$ et un nombre de pas `n_steps = 100`.
   - Comparez les résultats obtenus avec les deux méthodes. Comment les solutions diffèrent-elles ? Quelle méthode semble la plus stable ou la plus précise ?

## Visualisation avec gnuplot 
   - Créez un script gnuplot pour visualiser les résultats des simulations.
   - Le script doit tracer les courbes de la population de proies et de prédateurs en fonction du temps pour les deux méthodes (Euler explicite et implicite).
   - Utilisez le fichier de sauvegarde généré par chaque méthode pour tracer les courbes.
   - Le script GNUplot pourrait ressembler à ceci :

   ```gnuplot
   set terminal png size 800,600
   set output 'lotka_volterra.png'

   set title "Population Dynamics (Lotka-Volterra)"
   set xlabel "Time"
   set ylabel "Population"
   set grid

   plot "euler_explicit.dat" using 1:2 with lines title 'Proies (Euler Explicite)', \
        "euler_explicit.dat" using 1:3 with lines title 'Prédateurs (Euler Explicite)', \
        "euler_implicit.dat" using 1:2 with lines title 'Proies (Euler Implicite)', \
        "euler_implicit.dat" using 1:3 with lines title 'Prédateurs (Euler Implicite)'
   ```

   - Pour exécuter le script GNUplot, utilisez la commande suivante dans votre terminal :

   ```bash
   gnuplot -persist lotka_volterra.gnuplot
   ```
   - Cette commande générera un fichier PNG nommé `lotka_volterra.png` contenant les courbes des populations de proies et de prédateurs en fonction du temps, pour les deux méthodes numériques (Euler explicite et implicite).

## Bonus (Facultatif)

1. **Analyse de stabilité :**
   - Expérimentez avec différentes valeurs de pas de temps `h`. Quelle est la plus grande valeur de `h` pour laquelle les méthodes restent stables ? Commentez les résultats.

##  Documents à remettre
- Rédiger le document markdown.
- Déposez votre programme C++ sous la forme d'un fichier `.cpp`.
- Inclure également les fichiers .dat générés.

