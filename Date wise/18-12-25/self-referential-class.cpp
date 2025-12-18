/**
 * Program to demonstrate the concept of self referential classes in C++.
 */

#include <iostream>
using namespace std;

// Self-referential class
class Node {
public:
    int data;
    Node* next; // Pointer to the next node

    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

int main() {
    // Creating nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Linking nodes
    first->next = second;
    second->next = third;

    // Traversing the linked list
    Node* current = first;
    while (current != nullptr) {
        cout << "Node data: " << current->data << endl;
        current = current->next;
    }

    // Clean up memory
    delete first;
    delete second;
    delete third;

    return 0;
}