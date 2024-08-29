# Introduction à GIT (30mn)

Cet UE introduction au C++ s'appuie principalement sur des travaux personnels. Pour faciliter la correction des différents exercices nous allons utiliser un outil  de versionnage GIT.  Plus précisément , vous allez apprendre à: 
1. **Cloner un dépôt Git existant.**
2. **Créer et basculer sur une nouvelle branche locale.**
3. **Effectuer des modifications et les committer.**
4. **Mettre à jour votre branche avec les dernières modifications de la branche principale.**
 
## Etapes à suivre pour les séances de travaux pratiques

### 1. Cloner le dépôt des exercises

Commencez par cloner le dépôt Git distant sur votre machine locale.
```bash
git clone https://github.com/sabide/cpp-etu.git
```
Cette commande est à effectuer lors de la première séance seulement. 
Vous importez les énoncés des exercices de la séance.
C'est un clone de mon répertoire de travail privé que je mets à jour pour vous.
  
### 2. Naviguer dans le répertoire du Dépôt

Après le clonage, déplacez-vous dans le répertoire du dépôt cloné.
```bash
cd cpp-etu
```
Vous pouvez alors accéder aux énoncés qui sont au format Markdown.
Ils s'affichent très facilement à l'aide de VSCode.

### 3. Créer et basculer sur une nouvelle branche
Pour répondre aux questions, vous pouvez créer une branche locale, par exemple nommée `v`. Par exemple, nommons-la `jour-1`.
```bash
git checkout -b jour-1
```
Cette commande réalise deux actions :
- elle crée une nouvelle branche nommée `jour-1`.
- bascule sur cette branche.
À partir de maintenant, vous pouvez éditer du code.

### 4. Ajouter les modifications à l'index

Pour signaler à Git l'ajout de nouveaux fichiers à l'index Git, il vous faut taper la commande suivante :

```bash
git add .
```

Cette commande ajoute tous les fichiers modifiés. 
Vous pouvez également ajouter des fichiers spécifiques en remplaçant le point par le nom du fichier.

### 5. Commiter les modifications

L'opération de commit vous permet de tracer les modifications avec un message descriptif.

```bash
git commit -m "Réponses aux questions de l'exercice"
```
Tous ceci se passe en local sur votre répertoire......

### 6. Pousser la branche locale vers le dépôt distant

Si vous souhaitez partager votre branche avec le dépôt distant, poussez-la.
```bash
git push origin 00-Outils_pour_le_dev-reponses
```
<span style="color: red;"> Attention dans le cas de notre UE vous ne pouvez pas pousser  vos modifications sur le dépôt.</span>

### 7. Récupérer la correction
Pour récupérer la solution, nous allons fusionner la branche principale (main).
Pour simplifier la mise à jour de la correction, je donnerai les codes sources corrigés dans un sous-répertoire `sol`.
On revient ensuite sur la branche principale pour récupérer la correction :
```bash
git checkout main
git pull origin main
```
Puis, vous la fusionnez avec la commande:

```bash
git merge main
```

## Résumé des Commandes Utilisées

Voici un récapitulatif des commandes Git utilisées dans cet exercice :

```bash
# Cloner le dépôt
git clone <URL_DU_DEPOT>

# Naviguer dans le répertoire
cd repository

# Créer et basculer sur une nouvelle branche
git checkout -b 00-Outils_pour_le_dev-reponses

# Ajouter les modifications
git add .

# Commiter les modifications
git commit -m "Réponses aux questions de l'exercice"

# (Optionnel pour le tp) Pousser la branche locale vers le dépôt distant
git push origin 00-Outils_pour_le_dev-reponses 

# Basculer sur la branche principale 
git checkout main

# Tirer la correction (quand je la donne) de la branche principale
git pull origin main

# Basculer de nouveau sur votre branche de travail
git checkout 00-Outils_pour_le_dev-reponses

# Fusionner la branche principale dans votre branche
git merge main

# (Optionnel pour le tp) Pousser les modifications fusionnées
git push origin 00-Outils_pour_le_dev-reponses

```