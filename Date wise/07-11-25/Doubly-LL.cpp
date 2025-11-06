
#include <iostream>
using namespace std;

/*
    Doubly Linked List implementation with:
    1. Insertion at end
    2. Deletion at end
    3. Display (left-to-right)
    4. Count nodes
    5. Insertion at beginning
    6. Deletion at beginning
    7. Insertion at given position (1-based)
    8. Deletion at given position (1-based)
*/

// Node for the doubly linked list
struct Node {
    int data;      // payload
    Node* next;    // pointer to next node
    Node* prev;    // pointer to previous node
};

// Head points to first node, tail points to last node.
// Invariant: if list is empty, both head and tail are nullptr.
Node* head = nullptr;
Node* tail = nullptr;

// Insert a new node with 'value' at the end of the list.
// Time: O(1)
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) { // empty list
        head = newNode;
        tail = newNode;
    } else {     // non-empty list: link after tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Delete the last node of the list.
// Time: O(1)
void deleteAtEnd() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (head == tail) { // single node
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {            // more than one node
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

// Display all nodes from head to tail.
// Time: O(n)
void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Count total number of nodes.
// Time: O(n)
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert a new node with 'value' at the beginning of the list.
// Time: O(1)
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) { // empty list
        head = newNode;
        tail = newNode;
    } else {     // non-empty list: link before head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Delete the first node of the list.
// Time: O(1)
void deleteAtBeginning() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    if (head == tail) { // single node
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {            // more than one node
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

// Insert 'value' at 1-based 'position'.
// Valid positions: 1..(count+1)
// Time: O(n) due to traversal and validation
void insertAtPosition(int value, int position) {
    if (position < 1 || position > countNodes() + 1) {
        cout << "Invalid position\n";
        return;
    }
    if (position == 1) {               // insert at head
        insertAtBeginning(value);
        return;
    }
    if (position == countNodes() + 1) { // insert at tail
        insertAtEnd(value);
        return;
    }

    // Insert in the middle: find (position-1)-th node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    // Link newNode between temp and temp->next
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete node at 1-based 'position'.
// Valid positions: 1..count
// Time: O(n) due to traversal and validation
void deleteAtPosition(int position) {
    if (position < 1 || position > countNodes()) {
        cout << "Invalid position\n";
        return;
    }
    if (position == 1) {          // delete head
        deleteAtBeginning();
        return;
    }
    if (position == countNodes()) { // delete tail
        deleteAtEnd();
        return;
    }

    // Delete from the middle: move to the node at 'position'
    Node* temp = head;
    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }

    // Bypass 'temp' and free it
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

int main() {
    // Build: 10 <-> 20
    insertAtEnd(10);
    insertAtEnd(20);

    // Head insert: 5 <-> 10 <-> 20
    insertAtBeginning(5);

    // Insert 15 at position 3: 5 <-> 10 <-> 15 <-> 20
    insertAtPosition(15, 3);

    display(); // Output: 5 10 15 20
    cout << "Node count: " << countNodes() << endl; // Output: Node count: 4

    // Delete node at position 3: 5 <-> 10 <-> 20
    deleteAtPosition(3);
    display(); // Output: 5 10 20

    // Delete head: 10 <-> 20
    deleteAtBeginning();
    display(); // Output: 10 20

    // Delete tail: 10
    deleteAtEnd();
    display(); // Output: 10

    return 0;
}
