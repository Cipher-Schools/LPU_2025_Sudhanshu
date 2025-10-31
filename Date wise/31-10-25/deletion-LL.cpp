/*
    Program to delete a node from a singly linked list in C++
    1. from begin
    2. from end
    3. from given position
    4. by value
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteFromBegin(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteFromPosition(Node*& head, int position) {
    if (!head || position < 0) return;
    if (position == 0) {
        deleteFromBegin(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp && i < position - 1; ++i) temp = temp->next;
    if (!temp || !temp->next) return;
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void deleteByValue(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        deleteFromBegin(head);
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) temp = temp->next;
    if (!temp->next) return;
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void display(Node* head) {
    for (Node* temp = head; temp; temp = temp->next) cout << temp->data << " -> ";
    cout << "nullptr" << endl;
}

void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original List: ";
    display(head);

    deleteFromBegin(head);
    cout << "After deleting from beginning: ";
    display(head);

    deleteFromEnd(head);
    cout << "After deleting from end: ";
    display(head);

    deleteFromPosition(head, 1);
    cout << "After deleting from position 1: ";
    display(head);

    deleteByValue(head, 30);
    cout << "After deleting by value 30: ";
    display(head);

    clearList(head);
    return 0;
}
