#include <iostream>
#include <fstream>
#include <numeric>
#include "HashTable.h"
using namespace std;

void tableInput(int &size, int &step) {
    cout << endl << "Unesite velicinu tabele: "; cin >> size;
    do {
        cout << "Unesite korak linearnog adresiranja: ";
        cin >> step;
    }
    while (gcd(size, step) != 1);
}

int inputKey() {
    int key;
    cout << endl << "Unesite kljuc: "; cin >> key;
    return key;
}

void mainFunction(HashTable &hashMap) {
    int index, key;
    string value;
    do {
        cout << endl << "Izaberite opciju:" << endl;
        cout << "1)findKey(int key)" << endl;
        cout << "2)insertKey(int key, string value)" << endl;
        cout << "3)deleteKey(int key)" << endl;
        cout << "4)clear()" << endl;
        cout << "5)keyCount()" << endl;
        cout << "6)tableSize()" << endl;
        cout << "7)fillRatio()" << endl;
        cout << "8)stampa" << endl;
        cout << "9)performanse" << endl;
        cout << "10)kraj" << endl;
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
                hashMap.clear();
                break;
            case 5:
                cout << endl << "Broj kljuceva: " << hashMap.keyCount() << endl;
                break;
            case 6:
                cout << endl << "Velicina tabele: " << hashMap.tableSize() << endl;
                break;
            case 7:
                cout << endl << "Fill ratio: " << hashMap.fillRatio() << endl;
                break;
            case 8:
                cout << hashMap;
                break;
            case 9:
                hashMap.performance();
        }
    }
    while (index != 10);
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

    int size, step;
    tableInput(size, step);
    HashTable hashMap = HashTable(size, step);

    if (exercise == 1) {
        int openFile;
        do {
            cout << endl << "Unos podataka iz datoteke?" << endl << "0)ne" << endl << "1)da" << endl;
            cin >> openFile;
        }
        while (openFile < 0 || openFile > 1);
        if (openFile) {
            string line;
            try {
                ifstream inputFile("DZ3_Recnik_10K.txt");
                while (getline(inputFile, line)) {
                    int index = (int)(line.length() - 1), key;
                    string value;
                    while (line[index - 1] != '\t') --index;
                    key = stoi(line.substr(index, line.length() - index + 1));
                    index = 0;
                    while (line[index] != '\t') ++index;
                    value = line.substr(0, index);
                    hashMap.insertKey(key, value, false);
                }
                inputFile.close();
            }
            catch (...) {
                cout << endl << "Greska pri citanju iz fajla." << endl;
            }
        }
    }
    else hashMap.setAdaptive();
    mainFunction(hashMap);
}
