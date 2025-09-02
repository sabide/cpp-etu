# Installation et utilisation de Gmsh (mode librairie C++)

## 1. Installation depuis les sources

Téléchargez le code source de Gmsh :
```bash
git clone https://gitlab.onelab.info/gmsh/gmsh.git
cd gmsh
mkdir build && cd build
```
ou 
```bash
wget http://gmsh.info/src/gmsh-4.13.1-source.tgz 
tar xzvf gmsh-4.13.1-source.tgz 
cd gmsh-4.13.1-source
```

Compilation en **mode librairie** (sans interface graphique) :

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release \
         -DENABLE_FLTK=OFF \
         -DENABLE_BUILD_SHARED=ON \
         -DENABLE_BUILD_DYNAMIC=ON \
         -DCMAKE_INSTALL_PREFIX=~/local/gmsh/
make -j$(nproc)
sudo make install
```

Cette configuration compile Gmsh sans dépendances graphiques (`png`, `jpeg`, `fltk`), ce qui est plus simple pour une utilisation en C++.


## 3. Utiliser Gmsh dans un projet C++

### Arborescence minimale

```
mon_projet/
 ├── CMakeLists.txt
 └── main.cpp
```

### Compilation

```bash
mkdir build && cd build
cmake ..
make
./main
```

Cela génère un fichier `square.msh` qui contient le maillage 2D d’un carré.

---

## 4. Notes

* Si vous avez besoin de l’interface graphique, réactivez `-DENABLE_FLTK=ON` et installez `libpng` et `libjpeg`.
* Sous macOS avec Homebrew, pensez à ajouter au besoin :

  ```bash
  -DJPEG_INCLUDE_DIR=/opt/homebrew/opt/jpeg/include \
  -DJPEG_LIBRARY=/opt/homebrew/opt/jpeg/lib/libjpeg.dylib
  ```
