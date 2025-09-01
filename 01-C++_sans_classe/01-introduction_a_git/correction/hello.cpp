#include <iostream>
#include <string>  // pour std::string

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    string prenom;
    cout << "Entrez votre prénom : ";
    cin >> prenom;

    cout << "Bonjour " << prenom << " !" << endl;

    return 0;
}
