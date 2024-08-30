# TP1 - Compiler un code simple

## Objectifs
L'objectif du TD est l'écriture d'un simple code en C++ et de comprendre la chaîne de compilation.

## Rappels du cours

<details>
<summary>Compilation</summary>

```bash
# Build some source files (= generate object-files)
g++ -c file1.cpp file2.cpp file3.cpp --std=c++17
# Link the object-files into an executable.
g++ -o executable.x file1.o file2.o file3.o
# Execute the binary.
./the_exe
```
</details>

<details>
<summary>Utiliser Git</summary>

```bash
# Clone a repository.
git clone https://url_to_repository
# Move into the repository.
cd repository_folder
# Create and go on a new branch.
git switch -c new_branch
# Stage some changes (= prepare them for commit).
git add file1 file2 folder1
# Commit with a specific message on the current branch.
git commit -m "a message"
# Switch back to an existing branch.
git switch other_branch
# Put the commits of a branch named "work" into the current branch.
git merge work
```
</details>

<details>
<summary>Ecrire dans la terminal</summary>

```cpp
std::cout << "Value of var_a is:" << var_a << "." << std::endl;
```
</details>

<details>
<summary>Lire depuis le terminal</summary>

```cpp
std::cin >> var_a;
```
</details>

<details>
<summary>Utiliser un tableau dynamique</summary>

```cpp
auto values = std::vector<int>{ 1, 2, 3 };
auto first = values[0];
values.push_back(4);
```
</details>

<details>
<summary>Utiliser une chaîne de caractères</summary>

```cpp
auto first_name = std::string { "Medor" };
auto last_name = std::string { "TheDog" };
auto full_name = first_name + ' ' + last_name;
```
</details>


## Exercice 1 - Entrée / sortie (30 min)

1. Créez une nouvelle branche git nommée `01-cmake-rep` et commitez vos changements dessus avec le message "Hello".

2. Ouvrez le fichier [main.cpp](./main.cpp) et essayez de comprendre ce que font chacune de ses lignes.

3. Compilez ce programme de manière à générer un executable nommé "hello.x" et éditez le fichier de configuration adaptée.

3. Lancez le programme. Celui-ci vous demande votre nom, mais affiche toujours en sortie : "hello !".  

4. Modifiez le programme pour qu'il affiche votre prénom à la place.

5. Lancez le programme et passez-lui un très long nom (au moins 20 caractères). Que se passe-t-il ?  

6. Quelle classe de la librairie standard faudrait-il utiliser à la place du tableau de `char` pour stocker le nom de l'utilisateur ?

7. Modifiez le programme afin de réaliser ce changement.

8. Utiliser cmake pour automatiser la compilation.

## Exercice 2 - Erreur des grands nombres (30 min)

On cherche à calculer la solution du problème de Cauchy suivant 
$$y^\prime(t) = 3 y(t)−1, t \in [0,10]$$
avec la condition initiales données par $y(0) = 13$.
1. Donner la solution exacte de ce problème de Cauchy.
2. On considère à present le même problème mais avec une perutbation de la condition initiale $y_{\epsilon}(0) = 13 + \epsilon$ Calculer à l’aide d’un code en C la différence $y_{\epsilon}(10) − y(10)$. Commenter.

