/**
 * Program to implement Separate Chaining in Hash Table
 * 
 */

#include <iostream>
#include <list>
using namespace std;
#define TABLE_SIZE 10
class HashTable {
    list<int> table[TABLE_SIZE];
public:
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
    bool search(int key) {
        int index = hashFunction(key);
        for (int k : table[index]) {
            if (k == key) return true;
        }
        return false;
    }
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(25);
    ht.insert(30);
    
    cout << "Hash Table after insertion:" << endl;
    ht.display();
    
    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;
    
    ht.remove(15);
    cout << "Hash Table after deleting 15:" << endl;
    ht.display();
    
    return 0;
}