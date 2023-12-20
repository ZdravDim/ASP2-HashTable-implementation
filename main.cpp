#include <iostream>
#include <numeric>
#include "HashTable.h"
using namespace std;

int inputKey() {
    int key;
    cout << endl << "Unesite kljuc: "; cin >> key;
    return key;
}

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
        do {
            cout << "Unesite korak linearnog adresiranja: ";
            cin >> step;
        }
        while (step != 1 && gcd(size, step) != 1);
        HashTable hashMap = HashTable(size, step);
        int index, key;
        string value;
        do {
            cout << endl << "Izaberite opciju:" << endl;
            cout << "1)findKey(int key)" << endl;
            cout << "2)insertKey(int key, string value)" << endl;
            cout << "3)deleteKey(int key)" << endl;
            cout << "4)avgAccessSuccess()" << endl;
            cout << "5)avgAccessUnsuccess()" << endl;
            cout << "6)resetStatistics()" << endl;
            cout << "7)clear()" << endl;
            cout << "8)keyCount()" << endl;
            cout << "9)tableSize()" << endl;
            cout << "10)fillRatio()" << endl;
            cout << "11)stampa" << endl;
            cout << "12)kraj" << endl;
            cin >> index;
            switch (index) {
                case 1:
                    key = inputKey();
                    if (hashMap.findKey(key))
                        cout << endl << hashMap.index(key) << " " << *hashMap.findKey(key) << " " << key << endl;
                    else cout << endl << "Kljuc nije pronadjen." << endl;
                    break;
                case 2:
                    key = inputKey();
                    cout << "Unesite string: "; cin >> value;
                    hashMap.insertKey(key, value);
                    break;
                case 3:
                    key = inputKey();
                    hashMap.deleteKey(key);
                    break;
                case 4:
                    cout << endl << "AvgAccessSuccess: " << hashMap.avgAccessSuccess() << endl;
                    break;
                case 5:
                    cout << endl << "AvgAccessUnsuccess: " << hashMap.avgAccessUnsuccess() << endl;
                    break;
                case 6:
                    hashMap.resetStatistics();
                    break;
                case 7:
                    hashMap.clear();
                    break;
                case 8:
                    cout << endl << "Broj kljuceva: " << hashMap.keyCount() << endl;
                    break;
                case 9:
                    cout << endl << "Velicina tabele: " << hashMap.tableSize() << endl;
                    break;
                case 10:
                    cout << endl << "Fill ratio: " << hashMap.fillRatio() << endl;
                    break;
                case 11:
                    cout << hashMap;
                    break;
                default:
                    break;
            }
        }
        while (index != 12);
    } else {
        //modifikacija
    }
}
