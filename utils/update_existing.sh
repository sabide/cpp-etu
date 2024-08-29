#!/bin/bash

# Vérification des arguments
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <target_branch>"
    exit 1
fi

TARGET_BRANCH=$1
MAIN_BRANCH="main"

# Vérification si on est dans un dépôt Git
if [ ! -d .git ]; then
    echo "Ce script doit être exécuté dans un dépôt Git."
    exit 1
fi

# Basculer sur la branche cible
git checkout $TARGET_BRANCH || { echo "Échec du checkout sur la branche '$TARGET_BRANCH'."; exit 1; }

# Mise à jour des dernières modifications dans la branche cible
git pull origin $TARGET_BRANCH || { echo "Échec du pull sur la branche '$TARGET_BRANCH'."; exit 1; }

# Liste des fichiers existants dans la branche cible
FILES=$(git ls-tree -r --name-only HEAD)

# Basculer sur la branche principale
git checkout $MAIN_BRANCH || { echo "Échec du checkout sur la branche '$MAIN_BRANCH'."; exit 1; }

# Mise à jour des dernières modifications dans la branche principale
git pull origin $MAIN_BRANCH || { echo "Échec du pull sur la branche '$MAIN_BRANCH'."; exit 1; }

# Mettre à jour uniquement les fichiers existants dans la branche cible
for FILE in $FILES; do
    if git ls-tree -r --name-only HEAD | grep -q "^$FILE$"; then
        git checkout $MAIN_BRANCH -- "$FILE" || { echo "Échec de la mise à jour du fichier '$FILE'."; exit 1; }
    fi
done

# Basculer sur la branche cible à nouveau
git checkout $TARGET_BRANCH || { echo "Échec du checkout sur la branche '$TARGET_BRANCH'."; exit 1; }

# Ajouter les modifications à l'index
git add .

# Committer les modifications
git commit -m "Update existing files from '$MAIN_BRANCH' into '$TARGET_BRANCH'"

# Pousser les changements vers la branche cible
git push origin $TARGET_BRANCH || { echo "Échec du push sur la branche '$TARGET_BRANCH'."; exit 1; }

echo "Les fichiers existants dans '$TARGET_BRANCH' ont été mis à jour à partir de '$MAIN_BRANCH'."
