#include <iostream>
using namespace std;

// --- Question 2 ---
void incrementByPointer(int* ptr) {
    if (ptr != nullptr) {
        (*ptr)++;
    }
}

void incrementByReference(int& ref) {
    ref++;
}

// --- Question 3 ---
int* getPointerToElement(int arr[], int index) {
    return &arr[index]; // retourne l'adresse
}

int& getReferenceToElement(int arr[], int index) {
    return arr[index];  // retourne une référence
}

// --- Question 4 ---
int& getMax(int& x, int& y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "=== Q1: Declaration ===" << endl;
    int a = 5;
    int* p = &a;
    int& r = a; // r reste reference à a 

    cout << "a = " << a << ", adresse de a = " << &a << endl;
    cout << "p pointe sur " << p << ", *p = " << *p << endl;
    cout << "r (référence) = " << r << ", adresse de r = " << &r << endl;

    cout << "\n=== Q2: Passage par pointeur et référence ===" << endl;
    incrementByPointer(&a);
    cout << "Après incrementByPointer: a = " << a << endl;
    incrementByReference(a);
    cout << "Après incrementByReference: a = " << a << endl;

    cout << "\n=== Q3: Retour pointeur et référence ===" << endl;
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptrElem = getPointerToElement(arr, 2);
    int& refElem = getReferenceToElement(arr, 2);

    *ptrElem = 30; // modification via pointeur
    refElem = 300; // modification via référence

    cout << "Valeur du 3e élément modifiée: " << arr[2] << endl;

    cout << "\n=== Q4: getMax ===" << endl;
    int x = 10, y = 20;
    getMax(x, y) = 100; // modification directe de la plus grande valeur
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

