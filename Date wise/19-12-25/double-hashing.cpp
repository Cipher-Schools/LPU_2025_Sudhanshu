/**
 * Program to demonstrate Double Hashing in C++
 * for collision resolution in hash tables.
 */

#include <iostream>
#include <vector>

using namespace std;

class DoubleHashing {
private:
    vector<int> table;
    int capacity;
    int size;
    const int DELETED = -1;

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return 7 - (key % 7); // A prime number less than capacity
    }
public:
    DoubleHashing(int cap) : capacity(cap), size(0) {
        table.resize(capacity, -1);
    }
    bool insert(int key) {
        if (size == capacity) {
            cout << "Hash table is full!" << endl;
            return false;
        }

        int index = hash1(key);
        int stepSize = hash2(key);

        while (table[index] != -1 && table[index] != DELETED) {
            index = (index + stepSize) % capacity;
        }

        table[index] = key;
        size++;
        return true;
    }
    bool search(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        int startIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + stepSize) % capacity;
            if (index == startIndex) break; // Full loop
        }
        return false;
    }
    bool remove(int key) {
        int index = hash1(key);
        int stepSize = hash2(key);
        int startIndex = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = DELETED;
                size--;
                return true;
            }
            index = (index + stepSize) % capacity;
            if (index == startIndex) break; // Full loop
        }
        return false;
    }
};

int main() {
    DoubleHashing dh(11);

    dh.insert(10);
    dh.insert(22);
    dh.insert(31);
    dh.insert(4);
    dh.insert(15);
    dh.insert(28);
    dh.insert(17);
    dh.insert(88);
    dh.insert(59);

    cout << "Searching for 15: " << (dh.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (dh.search(99) ? "Found" : "Not Found") << endl;

    dh.remove(15);
    cout << "Searching for 15 after deletion: " << (dh.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}