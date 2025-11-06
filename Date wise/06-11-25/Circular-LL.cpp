/*
    Program to implement a Circular Singly Linked List in C++

    Supported operations:
    1. Insertion at end
    2. Deletion at end
    3. Display
    4. Count nodes
    5. Insertion at beginning
    6. Deletion at beginning
    7. Insertion at position
    8. Deletion at position

    Invariant (when list is non-empty):
      - head points to first node
      - tail points to last node
      - tail->next always points back to head (circular link)
*/

#include <iostream>
using namespace std;

// Node of circular singly linked list
struct Node {
    int data;
    Node* next;
};

// Global head and tail pointers for convenience
Node* head = nullptr;
Node* tail = nullptr;

/*
    Insert a node with value at the end of the list.
    Time: O(1)
*/
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    // Empty list: new node is both head and tail, points to itself
    if (!head) {
        head = newNode;
        tail = newNode;
        newNode->next = head; // circular link
    } else {
        // Link current tail to new node, move tail, repair circular link
        tail->next = newNode;
        tail = newNode;
        tail->next = head; // keep circular invariant
    }
}

/*
    Delete a node from the end of the list.
    Time: O(n) due to traversal to find penultimate node
*/
void deleteAtEnd() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    // Single node case
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // Find node just before tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head; // maintain circular link
    }
}

/*
    Display all nodes in the list starting from head.
    Stops when it returns to head.
    Time: O(n)
*/
void display() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

/*
    Count number of nodes in the list.
    Time: O(n)
*/
int countNodes() {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

/*
    Insert a node with value at the beginning (before head).
    Time: O(1)
*/
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!head) {
        // Empty list: new node points to itself
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        // New node becomes head; tail->next must point to new head
        newNode->next = head;
        head = newNode;
        tail->next = head; // maintain circular link
    }
}

/*
    Delete a node from the beginning (remove head).
    Time: O(1)
*/
void deleteAtBeginning() {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    // Single node case
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // Move head forward, relink tail to new head, delete old head
        Node* temp = head;
        head = head->next;
        tail->next = head; // maintain circular link
        delete temp;
    }
}

/*
    Insert a node with value at a 1-based position.
    Valid positions: [1, count+1]
    Time: O(n) (calls countNodes and possibly traverses)
*/
void insertAtPosition(int value, int position) {
    if (position < 1 || position > countNodes() + 1) {
        cout << "Invalid position\n";
        return;
    }
    // Position 1 means insert at beginning
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    // Last position means insert at end
    if (position == countNodes() + 1) {
        insertAtEnd(value);
        return;
    }
    // Traverse to node just before desired position
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    // Insert between temp and temp->next
    newNode->next = temp->next;
    temp->next = newNode;
}

/*
    Delete a node at a 1-based position.
    Valid positions: [1, count]
    Time: O(n) (calls countNodes and possibly traverses)
*/
void deleteAtPosition(int position) {
    if (position < 1 || position > countNodes()) {
        cout << "Invalid position\n";
        return;
    }
    // Position 1 means delete at beginning
    if (position == 1) {
        deleteAtBeginning();
        return;
    }
    // Last position means delete at end
    if (position == countNodes()) {
        deleteAtEnd();
        return;
    }
    // Traverse to node just before the one to delete
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // bypass node
    delete nodeToDelete;
}

int main() {
    // Build list: [10] -> [20] (circular)
    insertAtEnd(10);
    insertAtEnd(20);

    // Insert at beginning: [5] -> [10] -> [20]
    insertAtBeginning(5);

    display(); // Output: 5 10 20
    cout << "Node count: " << countNodes() << "\n"; // Output: 3

    // Insert 15 at position 3: [5] -> [10] -> [15] -> [20]
    insertAtPosition(15, 3);
    display(); // Output: 5 10 15 20

    // Delete node at position 2: [5] -> [15] -> [20]
    deleteAtPosition(2);
    display(); // Output: 5 15 20

    // Delete beginning: [15] -> [20]
    deleteAtBeginning();
    display(); // Output: 15 20

    // Delete end: [15]
    deleteAtEnd();
    display(); // Output: 15

    return 0;
}
