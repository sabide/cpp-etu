# Références et Pointeurs en C++ 

Comprendre la différence entre les **références** et les **pointeurs** en C++, ainsi que leur utilisation dans les fonctions, notamment pour le **passage d’arguments** et le **retour de valeurs**.


## Contexte 
En C++, les références et les pointeurs sont deux mécanismes fondamentaux pour manipuler la mémoire :  

- Une **référence** est un alias d’une variable existante (elle ne peut pas être nulle et doit être initialisée à la déclaration).  
- Un **pointeur** stocke l’adresse d’une variable et peut être redirigé vers une autre variable.  

Ces deux outils sont largement utilisés pour :  
- passer des arguments aux fonctions sans recopier les données,  
- retourner des valeurs sans créer de copies.  


## Questions et corrections

### 1. Déclaration et utilisation des références et des pointeurs
**Énoncé :**  
- Créez une variable entière `int a = 5;`.  
- Déclarez un pointeur `int* p` qui pointe sur `a`.  
- Déclarez une référence `int& r` qui fait référence à `a`.  
- Affichez les **valeurs** et les **adresses** de `a`, `p` et `r` pour illustrer leur relation.  

**Correction :**
```cpp
int a = 5;
int* p = &a;
int& r = a;

cout << "a = " << a << ", adresse de a = " << &a << endl;
cout << "p pointe sur " << p << ", *p = " << *p << endl;
cout << "r (référence) = " << r << ", adresse de r = " << &r << endl;
````

`&a`, `p` et `&r` donnent la même adresse mémoire. `*p` et `r` accèdent tous deux à la valeur de `a`.


### 2. Passage par référence et par pointeur aux fonctions

**Énoncé :**
Implémentez deux fonctions :

* `incrementByPointer(int* ptr)` qui incrémente la valeur pointée.
* `incrementByReference(int& ref)` qui incrémente la valeur référencée.

**Correction :**

```cpp
void incrementByPointer(int* ptr) { (*ptr)++; }
void incrementByReference(int& ref) { ref++; }

int a = 5;
incrementByPointer(&a);   // a = 6
incrementByReference(a);  // a = 7
```

Les deux fonctions modifient directement la variable. La référence simplifie la syntaxe, mais le pointeur permet de gérer `nullptr`.

---

### 3. Retourner des références et des pointeurs depuis une fonction

**Énoncé :**

* `int* getPointerToElement(int arr[], int index)` retourne un pointeur vers un élément.
* `int& getReferenceToElement(int arr[], int index)` retourne une référence vers un élément.

**Correction :**

```cpp
int* getPointerToElement(int arr[], int index) { return &arr[index]; }
int& getReferenceToElement(int arr[], int index) { return arr[index]; }

int arr[5] = {1, 2, 3, 4, 5};
int* ptrElem = getPointerToElement(arr, 2);
int& refElem = getReferenceToElement(arr, 2);

*ptrElem = 30;   // modifie arr[2]
refElem = 300;   // modifie arr[2] à nouveau
```

Le 3e élément du tableau devient `300`.


### 4. Étude de cas : fonction retournant une référence

**Énoncé :**
Implémentez `int& getMax(int& x, int& y)` qui retourne une référence vers le plus grand des deux.

**Correction :**

```cpp
int& getMax(int& x, int& y) { return (x > y) ? x : y; }

int x = 10, y = 20;
getMax(x, y) = 100;  // modifie directement y
```

Ici, `y` devient `100`.


### 5. Questions de réflexion

* **Différence fondamentale :**

  * Référence = alias obligatoire, ne peut pas être nulle.
  * Pointeur = variable contenant une adresse, peut être nul et redirigé.

* **Danger :**
  Retourner un pointeur ou une référence vers une **variable locale** est dangereux car la variable disparaît à la fin de la fonction.

* **Quand utiliser ?**

  * Références : pour un code simple et sûr (pas de `nullptr`).
  * Pointeurs : si l’on doit exprimer "absence de valeur" (`nullptr`) ou rediriger vers plusieurs cibles.

---

## Résultat attendu à l’exécution

```
=== Q1: Declaration ===
a = 5, adresse de a = 0x7ffee...
p pointe sur 0x7ffee..., *p = 5
r (référence) = 5, adresse de r = 0x7ffee...

=== Q2: Passage par pointeur et référence ===
Après incrementByPointer: a = 6
Après incrementByReference: a = 7

=== Q3: Retour pointeur et référence ===
Valeur du 3e élément modifiée: 300

=== Q4: getMax ===
x = 10, y = 100
```


## Compilation avec CMake

**CMakeLists.txt :**

```cmake
cmake_minimum_required(VERSION 3.10)
project(ExercicePointeursReferences)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pointeurs_references main.cpp)
```

**Commande de compilation :**

```bash
mkdir build
cd build
cmake ..
make
./pointeurs_references
```

