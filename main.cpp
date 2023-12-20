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
        int index;
        do {
            cout << endl << "Izaberite opciju:" << endl;
            cout << "1)findKey()" << endl;
            cout << "2)insertKey()" << endl;
            cout << "3)deleteKey()" << endl;
            cout << "4)avgAccessSuccess()" << endl;
            cout << "5)avgAccessUnsuccess()" << endl;
            cout << "6)resetStatistics()" << endl;
            cout << "7)clear()" << endl;
            cout << "8)keyCount()" << endl;
            cout << "9)tableSize()" << endl;
            cout << "10)fillRatio()" << endl;
            cin >> index;
            switch (index) {
                case 1:
                    cout << "";
                    break;
                case 2:
                    cout << "";
                    break;
                case 3:
                    cout << "";
                    break;
                case 4:
                    cout << "";
                    break;
                case 5:
                    cout << "";
                    break;
                case 6:
                    cout << "";
                    break;
                case 7:
                    cout << "";
                    break;
                case 8:
                    cout << "";
                    break;
                case 9:
                    cout << "";
                    break;
                case 10:
                    cout << "";
                    break;
                default:
                    break;
            }
        }
        while (index != 10);
    } else {
        //modifikacija
    }
}
