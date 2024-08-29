# cpp-exercice

Pour effacer les repertoire sol:
```bash
git switch to_publish
find . -type d -name "*sol*" | xargs git rm -r
git push origin to_publish
git switch main
```

ajouter une solution :
```bash
./utils/duplicate_dir.sh to_publish ./01-C++_sans_les_classes/00-Git/sol
```


