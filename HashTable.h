#ifndef ASP3_HASHTABLE_H
#define ASP3_HASHTABLE_H

#include <iostream>
#include "LinearHashing.h"
using namespace std;

class HashTable {
public:
    HashTable(int size, int s) : primeN(findN(size)), hashTableSize(size), map(new string[size]), linearHashing(new LinearHashing(s)) {
        for (int i = 0; i < size; ++i) map[i] = "";
    }
    ~HashTable() { delete linearHashing; delete[] map; }

    string* findKey(int key);
    bool insertKey(int key, string value);
    bool deleteKey(int key);
    int avgAccessSuccess();
    int avgAccessUnsuccess();
    void resetStatistics();
    void clear();
    int keyCount();
    int tableSize();
    double fillRatio();
    friend ostream& operator<<(ostream& os, const HashTable& table);

private:
    int hashMethod(int key) const;
    static bool isPrimeNumber(int number);
    static int findN(int n);

    int primeN = -1;
    int hashTableSize = -1, numOfKeys = 0;
    int avgSuccess = 0, avgUnsuccess = 0;
    string *map = nullptr;
    LinearHashing *linearHashing = nullptr;
};


#endif
