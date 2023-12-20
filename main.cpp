#include <iostream>
#include "HashTable.h"
using namespace std;

//STA AKO LINEARNA UDJE U BESKONACNU PETLJU!!!!!!!!!!!

int main() {
    int exercise = -1;
    do {
        cout << endl << "Unesite broj zadatka:" << endl;
        cout << "1)Tabela fiksne velicine" << endl;
        cout << "2)Modifikacija" << endl;
        cin >> exercise;
    }
    while (exercise < 1 || exercise > 2);
    if (exercise == 1) {
        int size, step;
        cout << endl << "Unesite velicinu tabele: "; cin >> size;
        cout << endl << "Unesite korak linearnog adresiranja: "; cin >> step;
        HashTable hashMap = HashTable(size, step);
        //...
    } else {

    }
}
