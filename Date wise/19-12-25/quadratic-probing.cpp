/**
 * Program to demonstrate quadratic probing in hash tables.
 * This implementation includes insertion, search, and deletion operations.
 */

#include <iostream>
#include <vector>
using namespace std;

class QuadraticProbingHashTable {
    vector<int> table;
    int capacity;
    int size;
    const int EMPTY = -1;
    const int DELETED = -2;
    
public:
    QuadraticProbingHashTable(int cap) : capacity(cap), size(0) {
        table.resize(capacity, EMPTY);
    }

    int hash(int key) {
        return key % capacity;
    }

    bool insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full!" << endl;
            return false;
        }

        int index = hash(key);
        int i = 1;
        while (table[index] != EMPTY && table[index] != DELETED) {
            index = (index + i * i) % capacity;
            i++;
        }

        table[index] = key;
        size++;
        return true;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return true;
            }
            index = (index + i * i) % capacity;
            i++;
            if (i == capacity) break; // Full loop
        }
        return false;
    }

    bool remove(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                size--;
                return true;
            }
            index = (index + i * i) % capacity;
            i++;
            if (i == capacity) break; // Full loop
        }
        return false;
    }
};

int main() {
    QuadraticProbingHashTable hashTable(11);

    hashTable.insert(10);
    hashTable.insert(22);
    hashTable.insert(31);
    hashTable.insert(4);
    hashTable.insert(15);
    hashTable.insert(28);
    hashTable.insert(17);
    hashTable.insert(88);
    hashTable.insert(59);

    cout << "Searching for 15: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (hashTable.search(99) ? "Found" : "Not Found") << endl;

    hashTable.remove(15);
    cout << "Searching for 15 after deletion: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}