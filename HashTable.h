#ifndef ASP3_HASHTABLE_H
#define ASP3_HASHTABLE_H

#include <iostream>
#include "LinearHashing.h"
using namespace std;

class HashTable {
public:
    HashTable(int size, int s) : primeN(findN(size)), hashTableSize(size), values(new string[size]), keys(new int[size]), linearHashing(new LinearHashing(s)) {
        for (int i = 0; i < size; ++i) {
            values[i] = "";
            keys[i] = -1;
        }
    }
    ~HashTable() { delete linearHashing; delete[] values; }

    string* findKey(int key);
    bool insertKey(int key, string value);
    bool deleteKey(int key);
    double avgAccessSuccess() const;
    double avgAccessUnsuccess() const;
    void resetStatistics();
    void clear();
    int keyCount() const;
    int tableSize() const;
    double fillRatio() const;
    friend ostream& operator<<(ostream& os, const HashTable& table);
    int index(int key);

private:
    int hashMethod(int key) const;
    static bool isPrimeNumber(int number);
    static int findN(int n);

    int primeN = -1;
    int hashTableSize = -1, numOfKeys = 0;
    int numSuccess = 0, totalSuccess = 0;
    int numUnsuccess = 0, totalUnsuccess = 0;
    string *values = nullptr;
    int *keys = nullptr;
    LinearHashing *linearHashing = nullptr;
};


#endif
