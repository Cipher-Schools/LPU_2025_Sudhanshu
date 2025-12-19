/**
 * Program to demonstrate linear probing in hashing
 */

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // -1 indicates empty slot
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    // Linear probing to find the next available slot
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            cout << "Hash table is full, cannot insert " << key << endl;
            return;
        }
    }
    hashTable[index] = key;
}

void displayTable() {
    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            cout << i << " --> " << hashTable[i] << endl;
        } else {
            cout << i << " --> " << "Empty" << endl;
        }
    }
}

int main() {
    initializeTable();
    
    insert(10);
    insert(20);
    insert(30);
    insert(25);
    insert(35);
    insert(5);
    
    displayTable();
    
    return 0;
}
