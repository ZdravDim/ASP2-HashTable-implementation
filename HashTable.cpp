#include <cmath>
#include <random>
#include "HashTable.h"
#define COEFFICIENT 2
#define AVG_LIMIT 2
#define SIZE_UP 0.7
using namespace std;

string *HashTable::findKey(int key, bool calculatePerformance) {
    int stepsCounter = 1;
    int address = hashMethod(key), startAddress = address;
    if (keys[address] == key) {
        if (calculatePerformance) {
            ++totalSuccess;
            ++numSuccess;
        }
        return &values[address];
    }
    else if (keys[address] == -1) {
        if (calculatePerformance) {
            ++totalUnsuccess;
            ++numUnsuccess;
        }
        return nullptr;
    }
    address = linearHashing -> getAddress(key, startAddress, ++stepsCounter) % hashTableSize;
    while (address != startAddress && keys[address] != key && keys[address] != -1)
        address = linearHashing -> getAddress(key, startAddress, ++stepsCounter) % hashTableSize;
    if (keys[address] == key) {
        if (calculatePerformance) {
            totalSuccess += stepsCounter;
            ++numSuccess;
        }
        return &values[address];
    }
    if (calculatePerformance) {
        totalUnsuccess += stepsCounter;
        ++numUnsuccess;
    }
    return nullptr;
}

bool HashTable::insertKey(int key, string value, bool printError) {
    if (keyCount() == hashTableSize) {
        if (printError) cout << endl << "Greska pri unosu: Tabela puna." << endl;
        return false;
    }
    int address = hashMethod(key), newAddress = address, attempt = 0;
    while (values[newAddress].length()) {
        if (keys[newAddress] == key) {
            cout << endl << "Kljuc vec postoji" << endl;
            return false;
        }
        newAddress = linearHashing -> getAddress(key, address, ++attempt) % hashTableSize;
    }
    values[newAddress] = value;
    keys[newAddress] = key;
    ++numOfKeys;
    if (adaptive) {
        if (fillRatio() >= SIZE_UP) adapt();
        privatePerformance();
    }
    return true;
}

bool HashTable::deleteKey(int key) {
    if (findKey(key)) {
        *findKey(key) = "";
        keys[findKey(key) - values] = -2;
        --numOfKeys;
        return true;
    }
    cout << endl << "Greska pri brisanju: Kljuc ne postoji." << endl;
    return false;
}

double HashTable::avgAccessSuccess() const {
    return totalSuccess ? (double)totalSuccess / numSuccess : 0;
}

double HashTable::avgAccessUnsuccess() const {
    return totalUnsuccess ? (double)totalUnsuccess / numUnsuccess : 0;
}

void HashTable::resetStatistics() {
    numSuccess = numUnsuccess = totalSuccess = totalUnsuccess = 0;
}

void HashTable::clear() {
    numOfKeys = 0;
    if (adaptive) {
        changeTableSize(initialSize);
        return;
    }
    for (int i = 0; i < hashTableSize; ++i) {
        values[i] = "";
        keys[i] = -1;
    }
}

int HashTable::keyCount() const {
    return numOfKeys;
}

int HashTable::tableSize() const {
    return hashTableSize;
}

double HashTable::fillRatio() const {
    return numOfKeys / (double)hashTableSize;
}

ostream &operator<<(ostream &os, const HashTable &table) {
    os << endl << "Tabela:" << endl;
    for (int i = 0; i < table.hashTableSize; ++i) {
        os << i << " ";
        if (table.values[i].length())
            os << table.values[i] << " " << table.keys[i] << endl;
        else cout << "EMPTY" << endl;
    }
    return os;
}

int HashTable::hashMethod(int key) const {
    return key % primeN;
}

bool HashTable::isPrimeNumber(int number) {
    if (number == 2) return true;
    for (int i = 2; i <= ceil(sqrt(number)); i++)
        if (number % i == 0) return false;
    return true;
}

int HashTable::findN(int number) {
    for (int i = number; i > 1; i--)
        if (isPrimeNumber(i))
            return i;
    return number;
}

int HashTable::index(int key) {
    return (int)(findKey(key) - values);
}

void HashTable::performance(bool privatePerformance) {
    resetStatistics();
    int min, max;
    for (int i = 0; i < hashTableSize; ++i)
        if (values[i].length())
            min = max = keys[i];

    for (int i = 0; i < hashTableSize; ++i)
        if (values[i].length()) {
            if (keys[i] > max) max = keys[i];
            else if (keys[i] < min) min = keys[i];
        }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < 10 * numOfKeys; ++i) {
        int randomNumber = dist(gen);
        findKey(randomNumber, true);
    }

    if (!privatePerformance) {
        cout << endl << "Prosecan broj pristupa" << endl;
        cout << "Uspesna pretraga: " << avgAccessSuccess() << endl;
        cout << "Neuspesna pretraga: " << avgAccessUnsuccess() << endl;
    }

    resetStatistics();
}

void HashTable::setAdaptive() {
    adaptive = true;
}

void HashTable::adapt() {
    int *oldKeys = new int[hashTableSize];
    auto *oldValues = new string[hashTableSize];

    for (int i = 0; i < hashTableSize; ++i) {
        oldKeys[i] = keys[i];
        oldValues[i] = values[i];
    }

    int newSize = (int)(hashTableSize * COEFFICIENT);
    primeN = findN(newSize);

    int oldTableSize = hashTableSize;
    changeTableSize(newSize);

    for (int i = 0; i < oldTableSize; ++i)
        if (oldValues[i].length())
            privateInsert(oldKeys[i], oldValues[i]);
}

void HashTable::privateInsert(int key, string value) {
    if (keyCount() == hashTableSize) {
        cout << "Private insert greska." << endl;
        return;
    }
    int address = hashMethod(key), newAddress = address, attempt = 0;
    while (values[newAddress].length())
        newAddress = linearHashing -> getAddress(key, address, ++attempt) % hashTableSize;
    values[newAddress] = value;
    keys[newAddress] = key;
}

void HashTable::changeTableSize(int newSize) {
    delete[] values;
    delete[] keys;
    hashTableSize = newSize;
    keys = new int[hashTableSize];
    values = new string[hashTableSize];
    for (int i = 0; i < hashTableSize; ++i) {
        keys[i] = -1;
        values[i] = "";
    }
}

void HashTable::privatePerformance() {
    performance(true);
    if (avgAccessSuccess() >= AVG_LIMIT || avgAccessUnsuccess() >= AVG_LIMIT) adapt();
    resetStatistics();
}
