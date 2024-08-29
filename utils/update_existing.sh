#!/bin/bash

# Vérification des arguments
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <target_branch> <directory1> [<directory2> ...]"
    exit 1
fi

TARGET_BRANCH=$1
MAIN_BRANCH="main"
shift 1  # Retire le premier argument (target_branch)
DIRECTORIES="$@"

# Vérification si on est dans un dépôt Git
if [ ! -d .git ]; then
    echo "Ce script doit être exécuté dans un dépôt Git."
    exit 1
fi

# Vérification si la branche cible existe
if ! git show-ref --verify --quiet refs/heads/$TARGET_BRANCH; then
    echo "La branche cible '$TARGET_BRANCH' n'existe pas."
    exit 1
fi

# Basculer sur la branche principale
git checkout $MAIN_BRANCH || { echo "Échec du checkout sur la branche '$MAIN_BRANCH'."; exit 1; }

# Mise à jour des dernières modifications
git pull origin $MAIN_BRANCH || { echo "Échec du pull sur la branche '$MAIN_BRANCH'."; exit 1; }

# Basculer sur la branche cible
git checkout $TARGET_BRANCH || { echo "Échec du checkout sur la branche cible '$TARGET_BRANCH'."; exit 1; }

# Mise à jour des dernières modifications
git pull origin $TARGET_BRANCH || { echo "Échec du pull sur la branche '$TARGET_BRANCH'."; exit 1; }

# Appliquer les modifications des fichiers existants dans les répertoires spécifiés
for DIR in $DIRECTORIES; do
    git diff --name-only $MAIN_BRANCH -- $DIR | xargs git checkout $MAIN_BRANCH -- || { echo "Échec du checkout des modifications dans le répertoire '$DIR'."; exit 1; }
done

# Ajouter les modifications à l'index
git add .

# Committer les modifications
git commit -m "Merge updated directories from branch '$MAIN_BRANCH' into '$TARGET_BRANCH'"

# Pousser les changements vers la branche cible
git push origin $TARGET_BRANCH || { echo "Échec du push sur la branche '$TARGET_BRANCH'."; exit 1; }

echo "Toutes les modifications des fichiers existants dans les répertoires spécifiés ont été propagées de '$MAIN_BRANCH' à '$TARGET_BRANCH'."

